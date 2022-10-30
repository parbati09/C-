vector <int> zigZagTraversal(Node* root)

    {

     vector<int>v;

     queue<Node*>q;

     q.push(root);

     int count=0;

     while(q.size()>0){

         count=count+1;

         vector<int>v1;

         int size=q.size();

         for(int i=0;i<size;i++){

             Node*cur=q.front();

             if(cur->left)q.push(cur->left);

             if(cur->right)q.push(cur->right);

             v1.push_back(cur->data);

             q.pop();

         }

         if(count%2==0)reverse(v1.begin(), v1.end());

         for(int j=0;j<v1.size();j++)v.push_back(v1[j]);

     }

     return v;

    }