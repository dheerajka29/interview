/*
 *Creating a BST tree.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
 * Data inside this structure can 
 * only take values in range
 * of 32bits signed integer.
 */
typedef struct tree_st {
    struct tree_st *left;
    struct tree_st *right;
    int data;
} tree_st_;

int 
find_subindex(int val, int * array, int len) {
     int index = 0;
     for(index;index < len; index++) {
         if (array[index] > val) {
	     return index;
	 }	 
     }	     
}	

/*
 * construct_tree_from_pre()
 * It takes the following arguments:
 * 1. preorder array
 * 2. Index element to be stored.
 * 3. "From" index element .
 * 4. "To" index element.
 * 5. length of preorder array.
 */ 

tree_st_ * 
construct_tree_from_pre(int * array,int index, int from,int to ,int len) {
    tree_st_ * temp = NULL;
    int i = 0;
    if( index >= len || from > to) {
        return NULL;
    }
    temp = malloc(sizeof(tree_st_));
    temp->left = temp->right = NULL;
    temp->data = array[index];
    for(i = from;i<=to;++i){
        if(array[i] > array[index] ){
	   break;
	}       	
    }	    
    if (from == to) 
	return temp; 
    temp->left = construct_tree_from_pre(array,index+1,index+1,i-1,len);
    temp->right = construct_tree_from_pre(array,i,i,to,len);
    return temp;
}

tree_st_ * 
construct_tree_from_pre_verify(int * array, int len) {
    if(len == 0 ) {
       return NULL;
    }	    
    int index = 0;
    return construct_tree_from_pre(array,index,0,len -1 ,len);
}

/*
 * Postorder Traversal
 */ 
void
display_tree_post( tree_st_ * node) {
    if(node) {
           display_tree_post(node->left);
           display_tree_post(node->right);
           printf("%d\n",node->data);
    }
}

/*
 * Preorder Traversal
 */ 
void
display_tree_pre( tree_st_ * node) {
    if(node) {
	   printf("%d\n",node->data);
           display_tree_pre(node->left);
           display_tree_pre(node->right);
    }
}

/*
 * Inorder Traversal
 */ 
void
display_tree_in( tree_st_ * node) {
    if(node) {
           display_tree_in(node->left);
           printf("%d\n",node->data);
           display_tree_in(node->right);
    }
}

/*
 * Returns the left child of the node .
 * If there is no child , then it returns
 * the node itself.
 */
tree_st_ * 
node_successor (tree_st_ * node ) {
     tree_st_ * temp ;	
     while(node) {
	   temp = node;  
           node = node->left; 
     }	    
     return temp; 
}	

/*
 * This API is used to delete
 * a key from a tree.
 * This will return the ordered tree.
 */

tree_st_ * 
delete_tree(tree_st_* node , int data) {
       if (node == NULL) {
           return node;
       }	 
       //Traverse the right subtree.
       if (data > node->data) {
           node->right = delete_tree(node->right,data);
       } // Traverse the left subtree.
       else if(data < node->data) {
           node->left = delete_tree(node->left,data);
       } else {   // This is it! Lets slay the beast.
	 tree_st_ * temp_node = NULL;     
	 //No left child 
         if(node->left == NULL) {
	    temp_node = node->right;
	    free(node);
	    return temp_node;
	 } else if (node->right == NULL) { //No Right Child
	    temp_node = node->left;
	    free(node);
	    return temp_node;
	 } else { //Both childs are there. 
	   /*
	    * Step 1 : Find inorder successor.
	    * Step 2 : Copy the data of this to current node.
	    * Step 3 : Call the delete_tree with successor value on 
	    *          right subtree as we now need to delete the successor 
	    *          node.
	    */ 
	    temp_node = node_successor(node->right);
            /* Good to access the temp_node without null check
             * as always a valid memory will be returned.
	     */ 
	    node->data = temp_node->data;
	    node->right = delete_tree(node->right,node->data);
	    return node;    
	 }	 
       }	       
}	

/*
 * Returns the height of the tree
 * w.r.t. root. 
 */ 
int height_tree (tree_st_ * node) {
    if (node == NULL) {
        return 0;
    } else {
      int lheight = height_tree(node->left);
      int rheight = height_tree(node->right);
      if(lheight < rheight) {
         return lheight + 1;
      } else {
         return rheight +1;
      }	      
    }	    
}	

/*
 * Return True or False
 * if element is found in BST.
 */ 
bool
search_tree(tree_st_ * node, int data) {
      if (node == NULL) {
          return false;
      }
      if (node->data == data) {
          return true;
      } else {
        if(data > node->data) {
           return search_tree(node->right,data);
        } else {
           return search_tree(node->left,data);
        }
      }
}

/*
 * Return Pointer to node
 * if found , else returns 
 * NULL.
 */

tree_st_ * search_tree_v2 (tree_st_ * node,
		           int data) {
     if (node == NULL) {
         return node;
     }
     if(node->data == data) {
        return node;
     } else {
       if(data > node->data) {
          return search_tree_v2(node->right,data);
       } else {
	  return search_tree_v2(node->left,data);     
       }	       
     }	     
}

/*
 * This function will take 2 parameters,
 * 1. Pointer to the tree and 2. Data value
 * It will return the modified head pointer as 
 * it is [If there is memory allocation error ,
 * it will return unmodified node.].
 */

tree_st_ *
tree_insert(tree_st_ * node, int data) {
    /*
     *If node is null , then first addition.
     */
    if(node == NULL) {
       tree_st_ * temp = NULL;
       temp = malloc(sizeof(tree_st_));
       if (temp == NULL) {
           return node;
       }
       memset(temp,'\0',sizeof(tree_st_));

       node = temp;
       node->data = data;
    } else {
       if(data > node->data) {
          node->right = tree_insert(node->right,data);
       } else if (data < node->data){
          node->left = tree_insert(node->left,data);
       }
    }
    return node;
}

/*
 *Driver Program.
 */ 
int main (int argc,char **argv) {
    tree_st_ * root = NULL, *temp = NULL;
    root = tree_insert(root,5);
    root = tree_insert(root,10);
    root = tree_insert(root,5);
    root = tree_insert(root,10);
    root = tree_insert(root,15);
    root = tree_insert(root,3);
    root = tree_insert(root,1);
    root = tree_insert(root,4);
    display_tree_pre(root);
    printf("Found is %s\n",search_tree(root,10)?"TRUE":"FALSE");
    if ((temp = search_tree_v2(root,10)) == NULL) {
        printf("V2 : Node not found\n");
    } else {
	printf("V2 : Node found with value %d \n",temp->data);    
    }	
    root = delete_tree(root,3);   
    display_tree_pre(root);
    int array [5] = {5,4,1,10,15}; 
    //temp = construct_tree_from_pre_verify(array,5);
    //display_tree_pre(temp); 

}

