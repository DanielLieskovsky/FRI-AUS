#pragma once

#include "priority_queue_list.h"
#include "../list/array_list.h"
#include <stdexcept>

namespace structures
{
	/// <summary> Prioritny front implementovany utriednym ArrayList-om. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prioritnom fronte. </typepram>
	template<typename T>
	class PriorityQueueSortedArrayList : public PriorityQueueList<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		PriorityQueueSortedArrayList();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Prioritny front implementovany utriednym ArrayList-om, z ktoreho sa prevezmu vlastnosti. </param>
		PriorityQueueSortedArrayList(PriorityQueueSortedArrayList<T>& other);

		/// <summary> Priradenie struktury. </summary>
		/// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
		Structure& assign(Structure& other) override;

		/// <summary> Vlozi prvok s danou prioritou do prioritneho frontu implementovaneho utriednym ArrayList-om. </summary>
		/// <param name = "priority"> Priorita vkladaneho prvku. </param>
		/// <param name = "data"> Vkladany prvok. </param>
		void push(int priority, const T& data) override;

	protected:
		/// <summary> Vrati index v utriedenom ArrayList-e, na ktorom sa nachadza prvok s najvacsou prioritou. </summary>
		/// <returns> Index prvku s najvacsou prioritou. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak je zoznam prazdny. </exception>
		int indexOfPeek() override;
	};

	template<typename T>
	inline PriorityQueueSortedArrayList<T>::PriorityQueueSortedArrayList() :
		PriorityQueueList<T>(new ArrayList<PriorityQueueItem<T>*>())
	{
	}

	template<typename T>
	inline PriorityQueueSortedArrayList<T>::PriorityQueueSortedArrayList(PriorityQueueSortedArrayList<T>& other) :
		PriorityQueueSortedArrayList<T>()
	{
		assign(other);
	}

	template<typename T>
	inline Structure& PriorityQueueSortedArrayList<T>::assign(Structure& other)
	{
		return PriorityQueueList<T>::assign(dynamic_cast<PriorityQueueSortedArrayList<T>&>(other));
	}

	template<typename T>
	inline void PriorityQueueSortedArrayList<T>::push(int priority, const T& data)
	{
		/*int predch = PriorityQueueList<T>::list_->size() -1;   
		PriorityQueueList<T>::list_->add(new PriorityQueueItem<T>(priority, data));
		while (predch >= 0 && PriorityQueueList<T>::list_->at(predch)->getPriority() < priority ) {
			Utils::swap(
				PriorityQueueList<T>::list_->at(predch),
				PriorityQueueList<T>::list_->at(predch + 1)
			);
			predch--;
		}*/

		int indexPozicie = list_->size() - 1;

		if (list_->size() != 0)
		{
			while (indexPozicie >= 0 && list_->at(indexPozicie)->getPriority() < priority)
			{
				indexPozicie--;
			}

			if (indexPozicie == list_->size() - 1 || indexPozicie == - 2)
			{
				list_->add(new PriorityQueueItem<T>(priority, data));
			}
			else if (indexPozicie == -1)
			{
				list_->insert(new PriorityQueueItem<T>(priority, data), 0);
			}
			else
			{
				list_->insert(new PriorityQueueItem<T>(priority, data), indexPozicie + 1);
			}
		}
		else 
		{
			list_->add(new PriorityQueueItem<T>(priority, data));
		}

		
	}

	template<typename T>
	inline int PriorityQueueSortedArrayList<T>::indexOfPeek()
	{
		//TODO 06: PriorityQueueSortedArrayList
		//throw std::runtime_error("PriorityQueueSortedArrayList<T>::index_of_peek: Not implemented yet.");

		if (list_->size() == 0) {
			throw std::logic_error("Prazdny list");
		}
		else {
			return size() - 1;
		}
	}
}