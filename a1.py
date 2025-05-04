class TelephoneBook:
  def __init__(self, name, tel_no):
    self.name = name
    self.tel_no = tel_no


def Insertion_QuadProbing():
    hashtable=[None for i in range(10)]
    num_records = int(input("\nEnter number of records : "))
    j=1
    for i in range(num_records):
        n = input("Enter name : ")
        t = int(input("Enter telephone no. : "))
        hashValue = t%10                         #hash function
        if hashtable[hashValue] is None:
            hashtable[hashValue] = TelephoneBook(n,t)   #creating obj of class and inserting into hashtable
        elif hashtable[hashValue] is not None:
            hashValue = (hashValue + (j*j)) % 10
            hashtable[hashValue] = TelephoneBook(n,t)
            j+=1
    return hashtable

 
def Insertion_DoubleHashing():
    hashtable = [None for _ in range(10)]
    num_records = int(input("\nEnter number of records: "))

    for _ in range(num_records):
        name = input("Enter name: ")
        telephone = int(input("Enter telephone no.: "))

        size = len(hashtable)
        h1 = telephone % 9
        h2 = 7 - (telephone % 7)
        
        inserted = False
        for i in range(size):
            index = (h1 + i * h2) % size
            if hashtable[index] is None: 
                hashtable[index] = TelephoneBook(name, telephone)
                inserted = True
                break
        
        if not inserted:
            print("Hash table is full or cannot resolve collision for:", name)

    return hashtable

def Display_QP(hash1):
    print("-------------------------------")
    print("Index\tName\tTelephone No.")
    print("-------------------------------")
    for obj in hash1:
        if(obj is None):
            print("-\t-\t-")
        if (obj is not None):
            print(hash1.index(obj),"\t",obj.name,"\t", obj.tel_no)
    print("-------------------------------")

def Display_DH(hash2):
    print("-------------------------------")
    print("Index\tName\tTelephone No.")
    print("-------------------------------")
    for obj in hash2:
        if(obj is None):
            print("-\t-\t-")
        if (obj is not None):
            print(hash2.index(obj),"\t",obj.name,"\t", obj.tel_no)
    print("-------------------------------")


def Search(hash1,hash2):
    n = input("Enter name to search: ")
    f1=0
    f2=0
    for obj in hash1:
        if(obj is None):
            continue
        if obj.name == n:
            print("\nFound in Hashtable-1 !")
            print("-------------------------------")
            print("Index\tName\tTelephone No.")
            print("-------------------------------")
            print(hash1.index(obj),"\t",obj.name,"\t", obj.tel_no)
            print("-------------------------------")
            f1=1

    for obj in hash2:
        if(obj is None):
            continue
        if obj.name == n:
            print("\nFound in Hashtable-2 !")
            print("-------------------------------")
            print("Index\tName\tTelephone No.")
            print("-------------------------------")
            print(hash2.index(obj),"\t",obj.name,"\t", obj.tel_no)
            print("-------------------------------")
            f2=1

    if f1==0 and f2==0:
        print("\nNot found !!!\n")


def main():
    # initialising hashtables to "None"
    hash1=[None for i in range(10)]
    hash2=[None for i in range(10)]
    print("-------------------------------")
    print("    Group-A Assignment-1")
    while True:
        print("-------------------------")
        print("\t1.Insert Value")
        print("\t2.Display")
        print("\t3.Search")
        print("\t4.Exit")
        print("-------------------------")
        ch = int(input("Enter choice : "))
        if ch==1:
            print("\nSelect collision method-")
            print("\t1.Quadratic Probing")
            print("\t2.Double Hashing")
            c = int(input("Enter choice : "))
            if c==1:
                hash1=Insertion_QuadProbing()
            elif c==2:
                hash2=Insertion_DoubleHashing()
        elif ch==2:
            print("\t1.Display QP")
            print("\t2.Display DH")
            c1 = int(input("Enter choice : "))
            if c1==1:
                Display_QP(hash1) #To display hashtable which uses quadratic probing collision method
            else:
                Display_DH(hash2)   #To display hashtable which uses double hashing collision method
        elif ch==3:
            Search(hash1,hash2)
        elif ch==4:
            quit()
        else:
            print("! Enter valid choice.")

main()

"""---output---

-------------------------------
    Group-A Assignment-1
-------------------------
	1.Insert Value
	2.Display
	3.Search
	4.Exit
-------------------------
Enter choice : 1

Select collision method-
	1.Quadratic Probing
	2.Double Hashing
Enter choice : 2

Enter number of records : 3
Enter name : khushi
Enter telephone no. : 65
Enter name : sweety
Enter telephone no. : 45
Enter name : neelam
Enter telephone no. : 12
-------------------------
	1.Insert Value
	2.Display
	3.Search
	4.Exit
-------------------------
Enter choice : 2
	1.Display QP
	2.Display DH
Enter choice : 2
-------------------------------
Index	Name	Telephone No.
-------------------------------
-	-	-
-	-	-
-	-	-
-	-	-
4 	 sweety 	 45
5 	 neelam 	 12
-	-	-
7 	 khushi 	 65
-	-	-
-	-	-
-------------------------------
-------------------------
	1.Insert Value
	2.Display
	3.Search
	4.Exit
-------------------------
Enter choice : 3
Enter name to search: khushi

Found in Hashtable-2 !
-------------------------------
Index	Name	Telephone No.
-------------------------------
7 	 khushi 	 65
-------------------------------
-------------------------
	1.Insert Value
	2.Display
	3.Search
	4.Exit
-------------------------
Enter choice : 4"""

