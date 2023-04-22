import os
os.environ["HDF5_USE_FILE_LOCKING"] = "FALSE"
import warnings
warnings.filterwarnings('ignore')

# ---------- 停用词库路径，若有变化请修改 -------------
stopwords_path = r'AI导论/垃圾信息识别/sms_pub.csv'
# ---------------------------------------------------

def read_stopwords(stopwords_path):
    """
    读取停用词库
    :param stopwords_path: 停用词库的路径
    :return: 停用词列表，如 ['嘿', '很', '乎', '会', '或']
    """
    stopwords = []
    # ----------- 请完成读取停用词的代码 ------------
    
    #----------------------------------------------
    data = open(stopwords_path,"r")
    while True:
        line = data.readline()
        line = line.replace("\n","")
        if not line:
            break
        else:
            stopwords.append(line)     
    return stopwords

# 读取停用词
stopwords = read_stopwords(stopwords_path)

# ----------------- 导入相关的库 -----------------
from sklearn.pipeline import Pipeline
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import BernoulliNB
from sklearn.naive_bayes import MultinomialNB
from sklearn.naive_bayes import ComplementNB

# pipline_list用于传给Pipline作为参数
pipeline_list = [
    # --------------------------- 需要完成的代码 ------------------------------
    
    # ========================== 以下代码仅供参考 =============================
    ('cv', CountVectorizer(token_pattern=r"(?u)\b\w+\b", stop_words=stopwords)),
    ('classifier', MultinomialNB())
    # ========================================================================
    
    # ------------------------------------------------------------------------
]

# 加载训练好的模型
import joblib
# ------- pipeline 保存的路径，若有变化请修改 --------
pipeline_path = 'AI导论/垃圾信息识别/pipeline.model'
# --------------------------------------------------
pipeline = joblib.load(pipeline_path)

def predict(message):
    """
    预测短信短信的类别和每个类别的概率
    param: message: 经过jieba分词的短信，如"医生 拿 着 我 的 报告单 说 ： 幸亏 你 来 的 早 啊"
    return: label: 整数类型，短信的类别，0 代表正常，1 代表恶意
            proba: 列表类型，短信属于每个类别的概率，如[0.3, 0.7]，认为短信属于 0 的概率为 0.3，属于 1 的概率为 0.7
    """
    label = pipeline.predict([message])[0]
    proba = list(pipeline.predict_proba([message])[0])
    
    return label, proba

# 测试用例
label, proba = predict('医生 拿 着 我 的 报告单 说 ： 幸亏 你 来 的 早 啊')
print(label, proba)