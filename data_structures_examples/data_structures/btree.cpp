#include "stdafx.h"
#include "btree.h"
#include <iostream>
#include <stack>

using std::stack;

void btree::_LRR(_nodePtr pnode)
{
	if(pnode==nullptr)
		return;
	_LRR(pnode->_left);
	std::cout<<pnode->_value<<"-";
	_LRR(pnode->_right);
}

btree::_nodePtr btree::_NextValue(_nodePtr pnode)
{
		return nullptr;
};

void btree::_transversal(_nodePtr pnode)
{
	if (_headPtr == nullptr) return;
	_nodePtr cur =pnode;
    _nodePtr next;
    while (cur != nullptr) {
        if (cur->_left == nullptr) {
			std::cout<<cur->_value<<"-";
            cur = cur->_right;
        } else {
            next = cur->_left;
            while (next->_right != nullptr && next->_right != cur)
                next = next->_right;
            if (next->_right == nullptr) {
                next->_right = cur;
                cur = cur->_left;
            } else {
				std::cout<<cur->_value<<"-";
                next->_right = nullptr;
                cur = cur->_right;
            }
        }
    }
}
void btree::_morris(_nodePtr pnode)
{
  _nodePtr current;
  _nodePtr pre;

  if(pnode == nullptr)
     return; 

  current = pnode;
  while(current != nullptr)
  {
    if(current->_left == nullptr)
    {
	  std::cout<<current->_value<<"-";
      current = current->_right;
    }
    else
    {
      /* Find the inorder predecessor of current */
      pre = current->_left;
      while(pre->_right != nullptr && pre->_right != current)
        pre = pre->_right;

      /* Make current as right child of its inorder predecessor */
      if(pre->_right == nullptr)
      {
        pre->_right = current;
        current = current->_left;
      }

     // MAGIC OF RESTORING the Tree happens here: 
      /* Revert the changes made in if part to restore the original
        tree i.e., fix the right child of predecssor */
      else
      {
        pre->_right = nullptr;
		std::cout<<current->_value<<"-";
        current = current->_right;
      } /* End of if condition pre->_right == NULL */
    } /* End of if condition current->_left == NULL*/
  } /* End of while */
}
int btree::_getNextSortOrderMorris(void)
{
	int retVal;
	_nodePtr pre;
	while(_currentNext!=nullptr)
	{
		if(_currentNext->_left == nullptr)
		{
			retVal=_currentNext->_value;
			_currentNext = _currentNext->_right;
			return retVal;
		}
	    /* Find the inorder predecessor of current */
		pre = _currentNext->_left;
		while(pre->_right != nullptr && pre->_right != _currentNext)
			pre = pre->_right;

		/* Make current as right child of its inorder predecessor */
		if(pre->_right == nullptr)
		{
			pre->_right = _currentNext;
			_currentNext = _currentNext->_left;
		}
		else
		{
			pre->_right = nullptr;
			retVal=_currentNext->_value;
			_currentNext = _currentNext->_right;
			return retVal;
		}
    }
}
int btree::_getNextSortOrder(void)
{
   int retVal;
   while (_currentNext != nullptr) {
        if (_currentNext->_left == nullptr) {
			retVal=_currentNext->_value;
            _currentNext = _currentNext->_right;
			return retVal;
        } else {
            _nextNext = _currentNext->_left;
            while (_nextNext->_right != nullptr && _nextNext->_right != _currentNext)
                _nextNext = _nextNext->_right;
            if (_nextNext->_right == nullptr) {
                _nextNext->_right = _currentNext;
                _currentNext = _currentNext->_left;
            } else {
				retVal=_currentNext->_value;
                _nextNext->_right = nullptr;
                _currentNext = _currentNext->_right;
				return retVal;
            }
        }
    }
}

void btree::LRR_stack(void)
{
	stack<_nodePtr> _stack;
	_nodePtr _currentNode;
	_currentNode=_headPtr->_left;
	_stack.push(_headPtr);
	while(!(_stack.empty() && _currentNode==nullptr))
	{
		if(_currentNode==nullptr)
		{
			_currentNode=_stack.top();
			std::cout<<_currentNode->_value<<"*-*";
			_stack.pop();
			_currentNode=_currentNode->_right;
		}
		else
		{
			_stack.push(_currentNode);
			_currentNode=_currentNode->_left;
		}
	}
	std::cout<<std::endl;
}

int btree::LRR_stack_next(void)
{
	int val;
	while(!(_stack.empty() && _currentNodeLRR==nullptr))
	{
		if(_currentNodeLRR==nullptr)
		{
			_currentNodeLRR=_stack.top();
			val=_currentNodeLRR->_value;
			_stack.pop();
			_currentNodeLRR=_currentNodeLRR->_right;
			return val;
		}
		else
		{
			_stack.push(_currentNodeLRR);
			_currentNodeLRR=_currentNodeLRR->_left;
		}
	}
	return 0;
}

void btree::setFirstLRR(void)
{
	_currentNodeLRR=_headPtr->_left;
	_stack.push(_headPtr);
	while(!(_stack.empty() && _currentNodeLRR==nullptr))
	{
		if(_currentNodeLRR==nullptr)
		{
			return;
		}
		else
		{
			_stack.push(_currentNodeLRR);
			_currentNodeLRR=_currentNodeLRR->_left;
		}
	}
}