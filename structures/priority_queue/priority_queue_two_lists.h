#pragma once

#include "priority_queue.h"
#include "priority_queue_limited_sorted_array_list.h"
#include "../list/linked_list.h"
#include <cmath>

namespace structures
{
	/// <summary> Prioritny front implementovany dvojzoznamom. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prioritnom fronte. </typepram>
	/// <remarks> Implementacia efektivne vyuziva prioritny front implementovany utriednym ArrayList-om s obmedzenou kapacitou a LinkedList. </remarks>
	template<typename T>
	class PriorityQueueTwoLists : public PriorityQueue<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		PriorityQueueTwoLists();

		PriorityQueueTwoLists(PriorityQueueTwoLists<T>& other);
		~PriorityQueueTwoLists();

		/// <summary> Priradenie struktury. </summary>
		/// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
		Structure& assign(Structure& other) override;

		/// <summary> Vrati pocet prvkov v prioritnom fronte implementovanom dvojzoznamom. </summary>
		/// <returns> Pocet prvkov v prioritnom fronte implementovanom dvojzoznamom. </returns>
		size_t size() override;

		/// <summary> Vymaze obsah prioritneho frontu implementovaneho dvojzoznamom. </summary>
		void clear() override;

		/// <summary> Vlozi prvok s danou prioritou do prioritneho frontu. </summary>
		/// <param name = "priority"> Priorita vkladaneho prvku. </param>
		/// <param name = "data"> Vkladany prvok. </param>
		void push(int priority, const T& data) override;

		/// <summary> Odstrani prvok s najvacsou prioritou z prioritneho frontu implementovaneho dvojzoznamom. </summary>
		/// <returns> Odstraneny prvok. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je prioritny front implementovany dvojzoznamom prazdny. </exception>
		T pop() override;

		/// <summary> Vrati adresou prvok s najvacsou prioritou. </summary>
		/// <returns> Adresa, na ktorej sa nachadza prvok s najvacsou prioritou. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je prioritny front implementovany dvojzoznamom prazdny. </exception>
		T& peek() override;

		/// <summary> Vrati prioritu prvku s najvacsou prioritou. </summary>
		/// <returns> Priorita prvku s najvacsou prioritou. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je prioritny front implementovany dvojzoznamom prazdny. </exception>
		int peekPriority() override;

	private:
		/// <summary> Smernik na prioritny front ako implementovany utriednym ArrayList-om s obmedzenou kapacitou . </summary>
		/// <remarks> Z pohladu dvojzoznamu sa jedna o kratsi utriedeny zoznam. </remarks>
		PriorityQueueLimitedSortedArrayList<T>* shortList_;

		/// <summary> Smernik na dlhsi neutriedeny zoznam. </summary>
		LinkedList<PriorityQueueItem<T>*>* longList_;
	};

	template<typename T>
	PriorityQueueTwoLists<T>::PriorityQueueTwoLists() :
		shortList_(new PriorityQueueLimitedSortedArrayList<T>()),
		longList_(new LinkedList<PriorityQueueItem<T>*>())
	{
	}

	template<typename T>
	PriorityQueueTwoLists<T>::PriorityQueueTwoLists(PriorityQueueTwoLists<T>& other) :
		PriorityQueueTwoLists<T>()
	{
		assign(other);
	}

	template<typename T>
	PriorityQueueTwoLists<T>::~PriorityQueueTwoLists()
	{
		clear();
	}

	template<typename T>
	Structure& PriorityQueueTwoLists<T>::assign(Structure& other)
	{
		if (this != &other) {
			PriorityQueueTwoLists<T>& otherPQTL = dynamic_cast<PriorityQueueTwoLists<T>&>(other);
			shortList_ = new PriorityQueueLimitedSortedArrayList<T>(*otherPQTL.shortList_);
			longList_ = new LinkedList<PriorityQueueItem<T>*>(*otherPQTL.longList_);
		}
		return *this;
	}

	template<typename T>
	size_t PriorityQueueTwoLists<T>::size()
	{
		return longList_->size() + (dynamic_cast<PriorityQueueList<T>*>(shortList_))->size();
	}

	template<typename T>
	void PriorityQueueTwoLists<T>::clear()
	{
		delete shortList_;
		delete longList_;
		shortList_ = nullptr;
		longList_ = nullptr;
	}

	template<typename T>
	void PriorityQueueTwoLists<T>::push(int priority, const T& data)
	{
		PriorityQueueItem<T>* item = shortList_->pushAndRemove(priority, data);
		if (item != nullptr) {
			longList_->add(item);
		}
	}

	template<typename T>
	T PriorityQueueTwoLists<T>::pop()
	{
		if (size() == 0) {
			throw std::logic_error("List je prazdny");
		} 
		if ((dynamic_cast<PriorityQueueList<T>*>(shortList_))->size() != 0) {
			(dynamic_cast<PriorityQueueSortedArrayList<T>*>(shortList_))->pop();
		}
		else {
			int num = (int)sqrt(longList_->size());
			shortList_->trySetCapacity((num > 4) ? number : 4);
			LinkedList<PriorityQueueItem<T>*> pomocnyLongList = new LinkedList<PriorityQueueItem<T>*>();
			while (longList_->size() != 0) {
				PriorityQueueItem<T>* kopia = longList_->removeAt(0);
				kopia = shortList_->pushAndRemove(kopia->getPriority(), kopia->accessData());
				if (kopia != nullptr) {
					pomocnyLongList.add(kopia);
				}
			}
			longList_ = pomocnyLongList;
			return (dynamic_cast<PriorityQueueSortedArrayList<T>*>(shortList_)).pop();
		}
	}

	template<typename T>
	T& PriorityQueueTwoLists<T>::peek()
	{
		return (dynamic_cast<PriorityQueueSortedArrayList<T>*>(shortList_))->peek();
	}

	template<typename T>
	int PriorityQueueTwoLists<T>::peekPriority()
	{
		return (dynamic_cast<PriorityQueueSortedArrayList<T>*>(shortList_))->peekPriority();
	}
}