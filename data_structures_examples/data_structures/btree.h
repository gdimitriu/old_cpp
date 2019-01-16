#pragma once
#include "stdafx.h"
#include <iostream>
#include <stack>
class btree
{
private:
	class _treeNode;
	typedef _treeNode* _nodePtr;
	class _treeNode
	{
	public:
		int _value;
		_nodePtr _left;
		_nodePtr _right;
		_nodePtr _parent;
		_treeNode(int val){_value=val;_left=nullptr;_right=nullptr;_parent=nullptr;}
	};
	_nodePtr _headPtr;
	_nodePtr _iteratorPtr;
public:
	btree()
	{
		_headPtr=nullptr;
		_iteratorPtr=nullptr;
	}
	void insert(int val)
	{
		if(nullptr==_headPtr)
		{
			_headPtr=new _treeNode(val);
			return;
		}
		_nodePtr _nodeTmpPtr;
		_nodeTmpPtr=_headPtr;
		while(_nodeTmpPtr!=nullptr)
		{
			if(_nodeTmpPtr->_value<val)
			{
				if(_nodeTmpPtr->_right!=nullptr)
					_nodeTmpPtr=_nodeTmpPtr->_right;
				else
				{
					_nodeTmpPtr->_right=new _treeNode(val);
					_nodeTmpPtr->_right->_parent=_nodeTmpPtr;
					return;
				}
			}
			else
			{
				if(_nodeTmpPtr->_left!=nullptr)
					_nodeTmpPtr=_nodeTmpPtr->_left;
				else
				{
					_nodeTmpPtr->_left=new _treeNode(val);
					_nodeTmpPtr->_left->_parent=_nodeTmpPtr;
					return;
				}
			}
		}
	}
	void LRR(void)
	{
//		_LRR(_headPtr);
		_morris(_headPtr);
		std::cout<<std::endl;
	}
	void setFirst(void)
	{
		_iteratorPtr=_FindMinNode(_headPtr);
	}
	int getNext(void)
	{
		_iteratorPtr=_NextValue(_iteratorPtr);
		if(_iteratorPtr!=nullptr)
			return _iteratorPtr->_value;
		else return 0;
	}
	int setFirstSortOrderMoris(void)
	{
		_currentNext=_headPtr;
		return _getNextSortOrderMorris();
	}
	int getNextSortOrderMoris(void)
	{
		int val;
		val=_getNextSortOrderMorris();
		return val;
	}
	void LRR_stack(void);
	void setFirstLRR(void);
	int LRR_stack_next(void);
private:
	_nodePtr _currentNext;
	_nodePtr _nextNext;
	std::stack<_nodePtr> _stack;
	_nodePtr _currentNodeLRR;

	static _nodePtr _NextValue(_nodePtr pnode);
	void _LRR(_nodePtr pnode);
	_nodePtr _FindMinNode(_nodePtr pnode)
	{
		int min=pnode->_value;
		_nodePtr tmpPtr=pnode;
		_nodePtr retPtr=pnode;
		tmpPtr=pnode->_left;
		while(tmpPtr!=nullptr)
		{
			if(tmpPtr->_value<min)
			{
				min=tmpPtr->_value;
				retPtr=tmpPtr;
			}
			tmpPtr=tmpPtr->_left;
		}
		return retPtr;
	}
	void _transversal(_nodePtr pnode);
	void _morris(_nodePtr pnode);
	int _getNextSortOrder(void);
	int _getNextSortOrderMorris(void);	
};
