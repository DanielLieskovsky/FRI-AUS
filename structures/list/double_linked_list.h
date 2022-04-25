#pragma once

#include "linked_list.h"

namespace structures
{
	// implementacne tipy: 
	//  - namiesto triedy List<T> mozete v triede DoubleLinkedList<T> 
	//    zdedit jednostranne zretazeny zoznam (LinkedList<T>).
	//    ak tak urobite, mozete mnoho metod odstranit a prekryt iba tie, 
	//    ktore maju z pohladu obojsmerne zretazeneho zoznamu vyznam a
	//    zvysok nechat na predka.
	//  - nezabudnite si vytvorit triedu pre prvok obojstranne zretazeneho zoznamu.
	//    opat tento prvok mozete zdedit z prvku jednostranne zretazeneho zoznamu.
	//  - ak vyuzijete dedicnost, budete moct vyuzit predkove iteratory, 
	//    takze ich nebudete musiet implementovat.
	
    /// <summary> Prvok jednostranne zretazeneho zoznamu. </summary>
    /// <typeparam name = "T"> Typ dat ukladanych v prvku. </typepram>
    template<typename T>
    class DoubleLinkedListItem : public DataItem<T>
    {
    public:
        /// <summary> Konstruktor. </summary>
        /// <param name = "data"> Data, ktore uchovava. </param>
        DoubleLinkedListItem(T data);

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> Prvok obojstranne zretazeneho zoznamu, z ktoreho sa prevezmu vlastnosti.. </param>
        DoubleLinkedListItem(DoubleLinkedListItem<T>& other);

        /// <summary> Destruktor. </summary>
        ~DoubleLinkedListItem();

        /// <summary> Getter predchadzajuceho prvku zretazeneho zoznamu. </summary>
        /// <returns> Predchadzajuci prvok zretazeneho zoznamu. </returns>
        DoubleLinkedListItem<T>* getPrevious();

        /// <summary> Setter predchadzajuceho prvku zretazeneho zoznamu. </summary>
        /// <param name´= "previous"> Novy predchadzajuci prvok zretazeneho zoznamu. </param>
        void setPrevious(DoubleLinkedListItem<T>* previous);

        /// <summary> Getter nasledujuceho prvku zretazeneho zoznamu. </summary>
        /// <returns> Nasledujuci prvok zretazeneho zoznamu. </returns>
        DoubleLinkedListItem<T>* getNext();

        /// <summary> Setter nasledujuceho prvku zretazeneho zoznamu. </summary>
        /// <param name´= "next"> Novy nasledujuci prvok zretazeneho zoznamu. </param>
        void setNext(DoubleLinkedListItem<T>* next);

    private:
        /// <summary> Nasledujuci prvok zretazeneho zoznamu. </summary>
        DoubleLinkedListItem<T>* next_;
        /// <summary> Predchadzajuci prvok zretazeneho zoznamu. </summary>
        DoubleLinkedListItem<T>* previous_;
    };

    //koniec deklaracie itemu ...........................................................................................................

    /// <summary> Obojstranne zretazeny zoznam. </summary>
    /// <typeparam name = "T"> Typ dat ukladanych v zozname. </typepram>
	template<typename T>
	class DoubleLinkedList : public List<T> 
	{
    public:
        /// <summary> Konstruktor. </summary>
        DoubleLinkedList();

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> DoubleLinkedList, z ktoreho sa prevezmu vlastnosti. </param>
        DoubleLinkedList(DoubleLinkedList<T>& other);

        /// <summary> Destruktor. </summary>
        ~DoubleLinkedList();

        /// <summary> Vrati pocet prvkov v zozname. </summary>
        /// <returns> Pocet prvkov v zozname. </returns>
        size_t size() override;

        /// <summary> Priradenie struktury. </summary>
        /// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
        /// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
        Structure& assign(Structure& other) override;

        /// <summary> Porovnanie struktur. </summary>
        /// <param name="other">Struktura, s ktorou sa ma tato struktura porovnat. </param>
        /// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
        bool equals(Structure& other) override;

        /// <summary> Vrati adresou prvok na indexe. </summary>
        /// <param name = "index"> Index prvku. </param>
        /// <returns> Adresa prvku na danom indexe. </returns>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        T& at(int index) override;

        /// <summary> Prida prvok do zoznamu. </summary>
        /// <param name = "data"> Pridavany prvok. </param>
        void add(const T& data) override;

        /// <summary> Vlozi prvok do zoznamu na dany index. </summary>
        /// <param name = "data"> Pridavany prvok. </param>
        /// <param name = "index"> Index prvku. </param>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        /// <remarks> Ak je ako index zadana hodnota poctu prvkov (teda prvy neplatny index), metoda insert sa sprava ako metoda add. </remarks>
        void insert(const T& data, int index) override;

        /// <summary> Odstrani prvy vyskyt prvku zo zoznamu. </summary>
        /// <param name = "data"> Odstranovany prvok. </param>
        /// <returns> true, ak sa podarilo prvok zo zoznamu odobrat, false inak. </returns>
        bool tryRemove(const T& data) override;

        /// <summary> Odstrani zo zoznamu prvok na danom indexe. </summary>
        /// <param name = "index"> Index prvku. </param>
        /// <returns> Odstraneny prvok. </returns>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        T removeAt(int index) override;

        /// <summary> Vrati index prveho vyskytu prvku v zozname. </summary>
        /// <param name = "data"> Prvok, ktoreho index sa hlada. </param>
        /// <returns> Index prveho vyskytu prvku v zozname, ak sa prvok v zozname nenachadza, vrati -1. </returns>
        int getIndexOf(const T& data) override;

        /// <summary> Vymaze zoznam. </summary>
        void clear() override;

        /// <summary> Vrati skutocny iterator na zaciatok struktury </summary>
        /// <returns> Iterator na zaciatok struktury. </returns>
        /// <remarks> Zabezpecuje polymorfizmus. </remarks>
        Iterator<T>* getBeginIterator() override;

        /// <summary> Vrati skutocny iterator na koniec struktury </summary>
        /// <returns> Iterator na koniec struktury. </returns>
        /// <remarks> Zabezpecuje polymorfizmus. </remarks>
        Iterator<T>* getEndIterator() override;

    private:
        /// <summary> Pocet prvkov v zozname. </summary>
        size_t size_;
        /// <summary> Prvy prvok zoznamu. </summary>
        DoubleLinkedListItem<T>* first_;
        /// <summary> Posledny prvok zoznamu. </summary>
        DoubleLinkedListItem<T>* last_;

    private:
        /// <summary> Vrati prvok zoznamu na danom indexe. </summary>
        /// <param name = "index"> Pozadovany index. </summary>
        /// <returns> Prvok zoznamu na danom indexe. </param>
        /// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>
        DoubleLinkedListItem<T>* getItemAtIndex(int index);

        //koniec deklaracie DDL ........................................................................................................

    private:
        /// <summary> Iterator pre DoubleLinkedList. </summary>
        class DoubleLinkedListIterator : public Iterator<T>
        {
        public:
            /// <summary> Konstruktor. </summary>
            /// <param name = "position"> Pozicia v zretazenom zozname, na ktorej zacina. </param>
            DoubleLinkedListIterator(DoubleLinkedListItem<T>* position);

            /// <summary> Destruktor. </summary>
            ~DoubleLinkedListIterator();

            /// <summary> Operator priradenia. Priradi do seba hodnotu druheho iteratora. </summary>
            /// <param name = "other"> Druhy iterator. </param>
            /// <returns> Vrati seba po priradeni. </returns>
            Iterator<T>& operator= (Iterator<T>& other) override;

            /// <summary> Porovna sa s druhym iteratorom na nerovnost. </summary>
            /// <param name = "other"> Druhy iterator. </param>
            /// <returns> True, ak sa iteratory nerovnaju, false inak. </returns>
            bool operator!=(Iterator<T>& other) override;

            /// <summary> Vrati data, na ktore aktualne ukazuje iterator. </summary>
            /// <returns> Data, na ktore aktualne ukazuje iterator. </returns>
            T operator*() override;

            /// <summary> Posunie iterator na dalsi prvok v strukture. </summary>
            /// <returns> Iterator na dalsi prvok v strukture. </returns>
            /// <remarks> Zvycajne vrati seba. Ak vrati iny iterator, povodny bude automaticky zruseny. </remarks>
            Iterator<T>& operator++() override;

        private:
            /// <summary> Aktualna pozicia v zozname. </summary>
            DoubleLinkedListItem<T>* position_;
        };
	};

    template<typename T>
    inline DoubleLinkedListItem<T>::DoubleLinkedListItem(T data)
        :  DataItem<T>(data),
           next_(nullptr),
           previous_(nullptr)
    {
    }

    template<typename T>
    inline DoubleLinkedListItem<T>::DoubleLinkedListItem(DoubleLinkedListItem<T>& other)
        :  DataItem<T>(other),
           next_(other.next_),
           previous_(other.previous_)
    {
    }

    template<typename T>
    inline DoubleLinkedListItem<T>::~DoubleLinkedListItem()
    {
        next_ = nullptr;
        previous_ = nullptr;
    }

    template<typename T>
    inline DoubleLinkedListItem<T>* DoubleLinkedListItem<T>::getPrevious()
    {
        return previous_;
    }

    template<typename T>
    inline void DoubleLinkedListItem<T>::setPrevious(DoubleLinkedListItem<T>* previous)
    {
        previous_ = previous;
    }

    template<typename T>
    inline DoubleLinkedListItem<T>* DoubleLinkedListItem<T>::getNext()
    {
        return next_;
    }

    template<typename T>
    inline void DoubleLinkedListItem<T>::setNext(DoubleLinkedListItem<T>* next)
    {
        next_ = next;
    }

    //koniec Itemu ...............................................................................................................

    template<typename T>
    inline DoubleLinkedList<T>::DoubleLinkedList() 
        : size_(0),
          first_(nullptr),
          last_(nullptr)
    {
    }

    template<typename T>
    inline DoubleLinkedList<T>::DoubleLinkedList(DoubleLinkedList<T>& other)
        : DoubleLinkedList<T>()
    {
        assign(other);
    }

    template<typename T>
    inline DoubleLinkedList<T>::~DoubleLinkedList()
    {
        clear();
    }

    template<typename T>
    inline size_t DoubleLinkedList<T>::size()
    {
        return size_;
    }

    template<typename T>
    inline Structure& DoubleLinkedList<T>::assign(Structure& other)
    {
        if (this != &other) {
            DoubleLinkedList<T>& otherLinkedList = dynamic_cast<DoubleLinkedList<T>&>(other);

            clear();

            DoubleLinkedListItem<T>* current = otherLinkedList.first_;

            while (current != nullptr) {
                add(current->accessData());
                current = current->getNext();
            }
        }

        return *this;
    }

    template<typename T>
    inline bool DoubleLinkedList<T>::equals(Structure& other)
    {
        if (this == &other) {
            return true;
        }

        DoubleLinkedList<T>* otherLinkedList = dynamic_cast<DoubleLinkedList<T>*>(&other);

        if (otherLinkedList == nullptr) {
            return false;
        }

        if (this->size_ != otherLinkedList->size_) {
            return false;
        }

        DoubleLinkedListItem<T>* curThis = this->first_;
        DoubleLinkedListItem<T>* curOther = otherLinkedList->first_;

        while (curThis != nullptr) {
            if (curThis->accessData() != curOther->accessData()) {
                return false;
            }
            curThis = curThis->getNext();
            curOther = curOther->getNext();
        }
        return true;
    }

    template<typename T>
    inline T& DoubleLinkedList<T>::at(int index)
    {
        Utils::rangeCheckExcept(index, size_, "Out of index");
        return getItemAtIndex(index)->accessData();
    }

    template<typename T>
    inline void DoubleLinkedList<T>::add(const T& data)
    {
        size_++;
        DoubleLinkedListItem<T>* novy = new DoubleLinkedListItem<T>(data);

        if (first_ == nullptr) {
            first_ = novy;
        }
        else {
            last_->setNext(novy);
            novy->setPrevious(last_);
        }
        last_ = novy;
    }

    template<typename T>
    inline void DoubleLinkedList<T>::insert(const T& data, int index)
    {
        if (size_ == index) {
            add(data);
        }
        else {
            Utils::rangeCheckExcept(index, size_, "Out of index");
            DoubleLinkedListItem<T>* novy = new DoubleLinkedListItem<T>(data);

            if (index == 0) {
                novy->setNext(first_);
                first_->setPrevious(novy);
                first_ = novy;
            }
            else {
                DoubleLinkedListItem<T>* pred = getItemAtIndex(index - 1);
                DoubleLinkedListItem<T>* atIndex = getItemAtIndex(index);

                pred->setNext(novy);
                novy->setPrevious(pred);

                novy->setNext(atIndex);
                atIndex->setPrevious(novy);
            }
            
        }
        size_++;
    }

    template<typename T>
    inline bool DoubleLinkedList<T>::tryRemove(const T& data)
    {
        int index = getIndexOf(data);

        if (index < 0) {
            return false;
        }
        else {
            T result = removeAt(index);
            return true;
        };
    }

    template<typename T>
    inline T DoubleLinkedList<T>::removeAt(int index)
    {
        Utils::rangeCheckExcept(index, size_, "Out of index");
        DoubleLinkedListItem<T>* delItem;

        if (size_ == 1) {
            delItem = first_;
            first_ = last_ = nullptr;
        }
        else if (index == (size_ - 1)) {
            DoubleLinkedListItem<T>* prevItem = getItemAtIndex(index - 1);
            delItem = prevItem->getNext();
            prevItem->setNext(nullptr);
            last_ = prevItem;
        }
        else {
            if (index == 0) {
                delItem = first_;
                first_ = first_->getNext();
                first_->setPrevious(nullptr);
                
            }
            else {
                DoubleLinkedListItem<T>* prevItem = getItemAtIndex(index - 1);
                DoubleLinkedListItem<T>* nextItem = getItemAtIndex(index + 1);

                delItem = prevItem->getNext();
                prevItem->setNext(nextItem);
                nextItem->setPrevious(prevItem);
            }
        }

        T result = delItem->accessData();
        delete delItem;
        size_--;
        return result;
    }

    template<typename T>
    inline int DoubleLinkedList<T>::getIndexOf(const T& data)
    {
        DoubleLinkedListItem<T>* pom = first_;
        int index = 0;
        while (pom != nullptr && pom->accessData() != data) {
            index++;
            pom = pom->getNext();
        }

        return pom != nullptr ? index : -1;
    }

    template<typename T>
    inline void DoubleLinkedList<T>::clear()
    {
        DoubleLinkedListItem<T>* current = first_;

        while (current != nullptr) {
            current = current->getNext();
            delete first_;
            first_ = current;
        }

        last_ = nullptr;
        size_ = 0;
    }

    template<typename T>
    inline Iterator<T>* DoubleLinkedList<T>::getBeginIterator()
    {
        return new DoubleLinkedListIterator(first_);
    }

    template<typename T>
    inline Iterator<T>* DoubleLinkedList<T>::getEndIterator()
    {
        return new DoubleLinkedListIterator(nullptr);
    }

    template<typename T>
    inline DoubleLinkedListItem<T>* DoubleLinkedList<T>::getItemAtIndex(int index)
    {
        if (index == size_ - 1) {
            return this->last_;
        }

        DoubleLinkedListItem<T>* current;

        if (index < size_ / 2) {
            current = first_;
            for (int i = 0; i < index; i++) {
                current = current->getNext();
            }
        }
        else {
            current = last_;
            for (int i = 0; i < index; i++)
            {
                current = current->getPrevious();
            }
        }
        return current;
    }

    //koniec DDL .............................................................................................................

    template<typename T>
    inline DoubleLinkedList<T>::DoubleLinkedListIterator::DoubleLinkedListIterator(DoubleLinkedListItem<T>* position)
        : position_(position)
    {
    }

    template<typename T>
    inline DoubleLinkedList<T>::DoubleLinkedListIterator::~DoubleLinkedListIterator()
    {
        this->position_ = nullptr;
    }

    template<typename T>
    inline Iterator<T>& DoubleLinkedList<T>::DoubleLinkedListIterator::operator=(Iterator<T>& other)
    {
        if (this != &other) {
            DoubleLinkedListIterator& otherIterator = dynamic_cast<LinkedListIterator&>(other);
            this->position_ = otherIterator.position_;
        }

        return *this;
    }

    template<typename T>
    inline bool DoubleLinkedList<T>::DoubleLinkedListIterator::operator!=(Iterator<T>& other)
    {
        DoubleLinkedListIterator* otherIterator = dynamic_cast<DoubleLinkedListIterator*>(&other);
        return otherIterator == nullptr || this->position_ != otherIterator->position_;
    }

    template<typename T>
    inline T DoubleLinkedList<T>::DoubleLinkedListIterator::operator*()
    {
        return this->position_->accessData();
    }

    template<typename T>
    inline Iterator<T>& DoubleLinkedList<T>::DoubleLinkedListIterator::operator++()
    {
        this->position_ = this->position_->getNext();
        return *this;
    }
}