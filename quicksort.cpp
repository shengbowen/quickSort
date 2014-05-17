#include<iostream>
#include<functional>
#include <algorithm>
#include<iostream>

 int count=0;
template<class BidirectionalIterator,class Compare>

void quickSort(BidirectionalIterator first,BidirectionalIterator last,Compare cmp)//默认数组的第一个元素为pivot
{
	if(first!=last)
	{

		//std::iter_swap(first,last);// 可选  以最后一个元素做pivot
		
		//可选以 first,last,mid 的中间值作为pivot;

		/*int len=last-first+1;
		if(len%2==0) len--;
		BidirectionalIterator mid=first+(len/2);
		if(cmp(*first,*mid)&&cmp(*mid,*last) || cmp(*last,*mid)&&cmp(*mid,*first)) std::iter_swap(first,mid);
		else if(cmp(*first,*last)&&cmp(*last,*mid) || cmp(*mid,*last)&&cmp(*last,*first)) std::iter_swap(first,last);*/
		
		BidirectionalIterator lfirst=first;
		BidirectionalIterator pivot=first;
		BidirectionalIterator lessp=lfirst;
		BidirectionalIterator upartion=++first;

		for(;upartion!=last;upartion++)
		{
			if(cmp(*upartion,*pivot))
			{
				lessp++;
				std::iter_swap(upartion,lessp);
				//lright++;
				count++;
			}
			else count++;
		}

		if(cmp(*upartion,*pivot))
		{
			lessp++;
			std::iter_swap(upartion,lessp);
			count++;
		}else count++;

		std::iter_swap(pivot,lessp);

		BidirectionalIterator temp=lessp;

		if(lessp!=lfirst) --lessp;
		quickSort(lfirst,lessp,cmp);
		if(temp!=last) ++temp;
			//if(lessp!=last) ++lessp;
		quickSort(temp,last,cmp);

	}
}

template<class BidirectionalIterator>

inline void quickSort(BidirectionalIterator first, BidirectionalIterator last ) {
  quickSort( first, last,
   std::less_equal<typename  std::iterator_traits< BidirectionalIterator >::value_type >()
  );
}


// 维基百科上的例子，从中知道如何向函数模板中加入默认类型参数
//#include <functional>
//#include <algorithm>
//#include <iterator>
//#include<iostream>
//static int count=0;
//template< typename BidirectionalIterator, typename Compare >
//void quick_sort( BidirectionalIterator first, BidirectionalIterator last, Compare cmp ) {
//  if( first != last ) {
//    BidirectionalIterator left  = first;
//    BidirectionalIterator right = last;
//    BidirectionalIterator pivot = left++;
//
//    while( left != right ) {
//      if( cmp( *left, *pivot ) ) {
//         ++left;
//      } else {
//         while( (left != right) && cmp( *pivot, *right ) )
//           right--;
//         std::iter_swap( left, right );
//      }
//	  count++;
//    }
//
//    if (cmp( *pivot, *left ))
//         --left;
//    std::iter_swap( first, left );
//
//    quick_sort( first, left, cmp );
//    quick_sort( right, last, cmp );
//  }
//}
//
//template< typename BidirectionalIterator >
//inline void quick_sort( BidirectionalIterator first, BidirectionalIterator last ) {
//  quick_sort( first, last,
//    std::less_equal< typename std::iterator_traits< BidirectionalIterator >::value_type >()
//  );
//}

int comp(const void*a,const void*b)
{
return*(int*)a-*(int*)b;
}

int main()
{

	int a[10000];
	int i=0;
	while(std::cin>>a[i])
	{
		i++;
	}
	quickSort(&a[0],&a[9999]);
	for(int k=0;k<=9999;k++)
		std::cout<<a[k]<<std::endl;

	std::cout<<count;//计算总的比较次数
	
}
