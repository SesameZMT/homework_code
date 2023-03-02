int man_n = name - man0;
        node * p = man[man_n]->next;
        if(!woman[p->name - woman0]->flag){
            a[1][man_n] = woman[p->name - woman0]->name;
            woman[p->name - woman0]->flag = true;
            woman[p->name - woman0]->like = name;
        }
        cout<<"_______";
        while(woman[p->name - woman0]->flag){
            cout<<'0';
            node * pw = woman[p->name - woman0];
            node * p2 = woman[p->name - woman0]->next;
            
            while(p2->name != name && p2->name != pw->like){
                p2 = p2->next;
            }
            if(p2->name == name){
                q.push(pw->like);
                pw->like = name;
                a[1][man_n] = pw->name;
                break;
            }
            else{
                p = p->next;
            }
        }
        if(!woman[p->name - woman0]->flag){
            a[1][man_n] = woman[p->name - woman0]->name;
            woman[p->name - woman0]->flag = true;
            woman[p->name - woman0]->like = name;
        }