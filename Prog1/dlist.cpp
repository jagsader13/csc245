#include <cstddef> 
#include <iostream>

using namespace std;

template<class ItemType>
struct NodeType
{
	ItemType info;
	NodeType<ItemType>*	next;
	NodeType<ItemType>*	back;
};

template <class ItemType>		
DList<ItemType>::DList()		// Class constructor
{
    length = 0;
    head = NULL;
}

template <class ItemType>
DList<ItemType>::~DList   ()		
{
	// Post: List is empty; All items have been deallocated.

}

template <class ItemType>
void DList<ItemType>::makeEmpty()
{
    // Post: List is empty; all items have been deallocated.
        while(head->next!=NULL)
        {
                delete head;
        }

}

template <class ItemType>
void DList<ItemType>::deleteItem (ItemType item)	
{
	//  Pre :  item to be deleted is passed in via parameter 
        // Post :  item is deleted if it exists in list 
        deleteLocation(location(item));

}

template <class ItemType>
bool DList<ItemType>::inList (ItemType item) const
{
	//  Pre :  item to be located is passed in via parameter 
        // Post :  function returns bool value if item is found 
        NodeType<ItemType>* temp = new NodeType<ItemType>;
        temp=head;
        bool found=false;
        while(temp!=NULL)
        {
                int num = temp ->info;
                if(num==item)
                {
                        found=true;
                        break;
                }
                else
                {
                        temp=temp->next;
                }
                
        }
        return found;
}  


template <class ItemType>
bool DList<ItemType>::isEmpty() const		
{
	// Post : function returns true if list is empty, false otherwise
        if(head==NULL)
        {
                return true;
        }
        else
        {
                return false;
        }
        
}

template <class ItemType>
void DList<ItemType>::print() const	
{
	// Pre  : List is not empty 
	// Post : Items in List have been printed to screen
        NodeType<ItemType>* temp = new NodeType<ItemType>;
        temp=head;
                while(temp!=NULL)
                {
                        cout << temp->info << endl;
                        temp= temp->next;

                }
}
	
template <class ItemType>
void DList<ItemType>::insertHead(ItemType item)	
{
	//  Pre : item to be inserted is passed in via parameter
        // Post : item is inserted at head of list;  Former first node is 
        //        linked back to this new one via double link;
        //        Length incremented;  Special case handled if list is empty 
	NodeType<ItemType>* newNode = new NodeType<ItemType>;
        newNode->info = item;    
        newNode->back = NULL;
        if (head != NULL)
        {
                head -> back = newNode;      
                newNode-> next = head;
        }
        else
        {
                newNode->next = NULL;
        }
        head = newNode;    
        length++;
}

template <class ItemType>
void DList<ItemType>::appendTail(ItemType item)
{
	//  Pre :  item to be inserted is passed in via parameter
        // Post :  item is added to tail of list; Former last node
        //         is linked to this new one via double link 
        NodeType<ItemType>* newNode = new NodeType<ItemType>;      
        newNode->info = item;
        last()-> next=newNode;
        newNode->back=last();
        newNode->next=NULL;
        length++;

}

template <class ItemType>
int DList<ItemType>::lengthIs() const	
{
	// Post : Function returns current length of list  
        return length;
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::location(ItemType item) const	
{
	//  Pre : item to be located is passed in via parameter 
        // Post : function returns address of item being searched for --
        //        if not found, NULL is returned  
	 NodeType<ItemType>* temp = new NodeType<ItemType>;
        temp=head;
        int find=item;
        bool found=false;
        while(temp!=NULL)
        {
                if(temp->info==item)
                {
                        found=true;
                        break;
                }
                else
                {
                        temp=temp->next;
                }
                
        }
        if(found==true)
        {
                return temp;
        }
        else
        {
                return NULL;
        }
}

template <class ItemType>
NodeType<ItemType>* DList<ItemType>::last() const	
{
	// Post : Function returns location of current last item in list
	NodeType<ItemType>* temp = new NodeType<ItemType>;
        temp=head;
        while(temp->next!=NULL)
        {
                temp=temp->next;
        }
        return temp;
}

template <class ItemType>
void DList<ItemType>::deleteLocation (NodeType<ItemType>* delPtr)	
{

	//  Pre : Item to be deleted exits in list and its location
        //        is passed in via parameter
                   
	// Post : Location passed in is removed from list;  Length
        //        is decremented, and location is deallocated 

        // Special Cases Handled for Deleting Only One Item in List,
        // The Head Item of List, and the Tail Item of List
       if ((delPtr-> next == NULL) && (delPtr -> back == NULL))    // only one item
        {
                head = NULL;
        }
        else if (delPtr-> next == NULL)   // >= 2 & it's the tail
        {
                 delPtr->back->next = NULL;
                 
        }
        else if (delPtr -> back == NULL)  // >= 2 & it's the head
        {
                delPtr->next->back = NULL;
                head = delPtr->next;
                
        }
        else  // >= 2 & it's in the middle
        {
                delPtr->next->back = delPtr->back;
                delPtr->back->next = delPtr->next;
               
        }
        length--;
        
}
