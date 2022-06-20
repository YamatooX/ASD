using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading.Tasks;

namespace Kmpresor
{
    class Program
    {
        static void heapify(ArrayList list, int size, int iterator)
        {
            KeyValuePair<char, int> iteratorPair = (KeyValuePair<char, int>)list[iterator];

            int largest = iterator;
            KeyValuePair<char, int> largestPair = (KeyValuePair<char, int>)list[largest];
            int largestValue = largestPair.Value;

            int leftChild = 2 * iterator + 1;
            KeyValuePair<char, int> leftChildPair = (KeyValuePair<char, int>)list[leftChild];
            int leftChildValue = leftChildPair.Value;

            int rightChild = 2 * iterator + 2;
            KeyValuePair<char, int> rightChildPair = (KeyValuePair<char, int>)list[rightChild];
            int rightChildValue = rightChildPair.Value;

            if (leftChild < size && leftChildValue > largestValue)
                largest = leftChild;

            if (rightChild < size && rightChildValue > largestValue)
                largest = rightChild;

            if (!iteratorPair.Equals(largestPair))
            {
                (largestPair, iteratorPair) = (iteratorPair, largestPair);
                heapify(list, size, largest);
            }
        }


        static void CountCharacters(char[] charArray, int[] intArray, string text)
        {
            for (int j = 32; j < 127; j++)
            {
                int counter = 0;
                for (int i = 0; i < text.Length; i++)
                {
                    if ((char)j != text[i])
                        charArray[j] = (char)j;
                    if ((char)j == text[i])
                        counter++;
                }
                intArray[j] = counter;
                //Console.WriteLine($"{charArray[j]}: {intArray[j]}");
            }
        }

        static void heapifyList(ArrayList list, int size)
        {
            for (int i = (size) / 2 - 1; i >= 0; i--)
                heapify(list, size, i);
        }
        static string ReadFromFileToString(string str)
        {
            string newString = "";
            Stream s = new FileStream(@"D:\Studia\Zajęcia\Algorytmy i struktury danych\ćw\ASD\Projekt2 - kompresor\Kmpresor\plot.txt", FileMode.Open);
            int val = 0;

            while (true)
            {
                val = s.ReadByte();

                if (val < 0)
                    break;
                newString += (char)val;
            }

            return newString;
        }

        static void EnqueArraysWithAnyValues(ArrayList queue, char[] charArr, int[] intArr)
        {
            Dictionary<char, int> dictionary = new Dictionary<char, int>();
            for (int i = 0; i < 127; i++)
            {
                if (intArr[i] != 0)
                {
                    dictionary.Add(charArr[i], intArr[i]);
                }
            }

            foreach (KeyValuePair<char, int> c in dictionary)
            {
                queue.Add(c);
                //Console.WriteLine(c);
            }
        }
        static string QueueToString(ArrayList queue)
        {
            string s = "";
            foreach (var item in queue)
            {
                s += item.ToString();
            }

            //Console.WriteLine(s);
            return s;
        }

        static void PutIntoFile(ArrayList queue)
        {
            StreamWriter sw = new StreamWriter(@"D:\Studia\Zajęcia\Algorytmy i struktury danych\ćw\ASD\Projekt2 - kompresor\Kmpresor\compessedFile.txt");

            sw.WriteLine(QueueToString(queue));

            Console.WriteLine("Done");
            sw.Close();
        }

        static void Main(string[] args)
        {
            var queue = new ArrayList();
            string stringToCompress = "";
            string arr = ReadFromFileToString(stringToCompress);
            
            char[] charArray = new char[127];
            int[] intArray = new int[127];

            CountCharacters(charArray, intArray, arr);

            EnqueArraysWithAnyValues(queue, charArray, intArray);

            PutIntoFile(queue);

            heapifyList(queue, queue.Count-1);

            for (int i = 0; i < queue.Count; i++)
                Console.WriteLine(queue[i]);
        }
    }
}
