#include<bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode{
	public:
	T data;
	vector<TreeNode<T>*> children;
	TreeNode(T data){
	this->data=data;
	}
};
TreeNode<int>* takeinputlevelwise(){
	int rootdata;
	cin>>rootdata;
	TreeNode<int>* root=new TreeNode<int>(rootdata);
	queue<TreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
	    TreeNode<int>* front=pendingnodes.front();
	    pendingnodes.pop();
	    int n;
	    cin>>n;
	    for(int i=0;i<n;i++){
           int childdata;
           cin>>childdata;
           TreeNode<int>* child=new TreeNode<int>(childdata);
           front->children.push_back(child);
           pendingnodes.push(child);
	    }
	}
	return root;
}
void printlevelwise(TreeNode<int>* root){
	queue<TreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
	    TreeNode<int>* front=pendingnodes.front();
	    pendingnodes.pop();
	    cout<<front->data<<":";
	    for(int i=0;i<front->children.size();i++){
               cout<<front->children[i]->data<<",";
               pendingnodes.push(front->children[i]);
	    }
	    cout<<endl;
	}
}
TreeNode<int>* nextlargest(TreeNode<int>* root,int n){
	TreeNode<int>* ans=NULL;
	if(root->data>n){
		ans=root;
	}
	for(int i=0;i<root->children.size();i++){
           TreeNode<int>* small=nextlargest(root->children[i],n);
           if(small==NULL){
           	continue;
           }
           else{
           	    if(ans==NULL){
           	    	ans=small;
           	    }
                else if(small->data<ans->data && small->data>n){
           	       ans=small;
                 }
           }
	}
	return ans;

}
int main(){
	int n;
	cin>>n;
	TreeNode<int>* root=takeinputlevelwise();
	printlevelwise(root);
	cout<<nextlargest(root,n)->data<<endl;
}