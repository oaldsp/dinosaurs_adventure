#pragma once

#include <iostream>

namespace List{

	template<class TL>
	class List{
	private:
		//Classe alinhada 
		template<class TE>
		class Element{
		private:
			Element<TE>* pNext;
			TE* pData;
		public:
			Element():pNext(NULL), pData(NULL){};
			~Element(){
			pNext = NULL;
			pData  = NULL;
			}
			void setNext(Element<TE>* pTemp){pNext = pTemp;}
			Element<TE>* getNext(){ return pNext;}
			void setData(TE*  pTemp){pData = pTemp;}
			TE*  getData(){return pData;}
		};
		//Atributos:
		Element<TL>* pFirst;
		Element<TL>* pLast;
		unsigned int size;
		//Metodos:
		Element<TL>* getFirst(){return pFirst;}
		Element<TL>* getLast(){return pLast;}
		void setElement(Element<TL>* pTemp);
	public:
		List();
		~List();

		unsigned int getSize();
	
		void clear();
		void push(TL* pTemp);
	
		TL* operator[](unsigned int pos);
		TL* pop(TL* pTemp);
		TL* pop(unsigned int pos);
	};

	//Metodos privados
	template<class TL>
	void List<TL>::setElement(Element<TL>* pTemp){
		if(pTemp != NULL){
			if(pFirst == NULL)
				pFirst = pTemp;
			else
				pLast->setNext(pTemp);   
			pLast =  pTemp;
			size++;
		}
	}

	//Metodos publicos
	template<class TL>
	List<TL>::List(): pFirst(NULL), pLast(NULL), size(0){}

	template<class TL>
	List<TL>::~List(){
		//clear();
	}

	template<class TL>
	unsigned int List<TL>::getSize(){
		return size;
	}

	template<class TL>
	void List<TL>::clear(){
		if(pFirst != NULL){
			Element<TL>* pTemp1 = pFirst;
			Element<TL>* pTemp2 = pFirst->getNext();
		
			while(pTemp1 != NULL){
				delete pTemp1->getData();
				delete pTemp1;
				pTemp1 = pTemp2;
				if(pTemp1 !=NULL)
					pTemp2 = pTemp1->getNext(); 	
			}

			pFirst = pLast = NULL;
			size = 0;
		}
	}
		
	template<class TL>
	void List<TL>::push(TL* pTemp){
		if(pTemp != NULL){	
			Element<TL>* pElement = new Element<TL>();
			pElement->setData(pTemp);
			setElement(pElement);
		}
	}

	template<class TL>
	TL* List<TL>::operator[](unsigned int pos){
		if(pos >= size)
			exit(1);

		Element<TL>* pTemp = pFirst;

		for(unsigned int i=0; i<pos; i++)
			pTemp = pTemp->getNext();
		
		return pTemp->getData();
	}

	template<class TL>
	TL* List<TL>::pop(TL* pTemp){
		Element<TL>* pReturn = pFirst;//ponteiro para retornar 
		Element<TL>* pSew    = NULL;//ponteiro para costurar

		while(pTemp != NULL){
			if(pReturn->getData() == pTemp){
				if(pReturn == pFirst)
					pFirst = pReturn->getNext();
				else if(pReturn == pLast){
					pLast = pSew;
					pSew->setNext(NULL);
				}else
					pSew->setNext(pReturn->getNext());	
			delete pReturn;
			size--;
			return pTemp;
			}
			pSew = pReturn;
			pReturn = pReturn->getNext();
		}
		return NULL;
	}

	template<class TL>
	TL* List<TL>::pop(unsigned int pos){
		if(pos>=size)
			exit(1);	
		 
		Element<TL>* pSew    = NULL;//ponteiro para costurar
		Element<TL>* pReturn = pFirst;//ponteiro para retornar 

		for(int i=0; i<pos; i++){
			pSew = pReturn;
			pReturn = pReturn->getNext();
		} 

		if(pReturn == pFirst)
			pFirst = pReturn->getNext();
		else if(pReturn == pLast){
			pLast = pSew;
			pSew->setNext(NULL);
		}else
			pSew->setNext(pReturn->getNext());	
		
		
		TL* pTemp = pReturn->getData();
		delete pReturn;
		size--;
		
		return pTemp;
	}
}//fim do namespace List
