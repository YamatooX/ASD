using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using HoffmanCompresor;
using System.IO;

namespace HuffmanTest
{
    class Program
    {

        static void heapify(int[] arr, char[] array, int n, int i)
        {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < n && arr[l] > arr[largest])
                largest = l;

            if (r < n && arr[r] > arr[largest])
                largest = r;

            if (largest != i)
            {
                (arr[i], arr[largest]) = (arr[largest], arr[i]);
                (array[i], array[largest]) = (array[largest], array[i]);
                heapify(arr, array, n, largest);
            }
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

        static Dictionary<char, byte> MakeDictionary(string text)
        {
            char[] charArray = new char[127];
            int[] intArray = new int[127];

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
            }

            for (int i = 0; i < intArray.Length; i++)
                heapify(intArray, charArray, intArray.Length, i);

            byte[] byteArr = new byte[charArray.Length];

            for (int i = 0; i < byteArr.Length; i++)
            {
                byteArr[i] = (byte)i;
            }

                Dictionary<char, byte> dictionary = new Dictionary<char, byte>();
            for (int i = 0; i < 127; i++)
            {
                if (intArray[i] != 0)
                {
                    dictionary.Add(charArray[i], byteArr[i]);
                }
            }

            return dictionary;
        }

        static void PutIntoFile(BitArray queue, Dictionary<char, byte> dict)
        {
            StreamWriter sw = new StreamWriter(@"D:\Studia\Zajęcia\Algorytmy i struktury danych\ćw\ASD\Projekt2 - kompresor\Kompresor\HoffmanCompresor\compessedFile.txt");

            foreach (var item in dict)
            {
                sw.WriteLine(item);
            }

            foreach (bool item in queue)
            {
                char grzyb;
                if (item == true)
                    grzyb = '1';
                else
                    grzyb = '0';

                sw.Write(grzyb);
            }

            Console.WriteLine("Done");
            sw.Close();
        }

        static void Main(string[] args)
        {
            var list = new ArrayList();
            string stringTocompress = "";
            string input = ReadFromFileToString(stringTocompress);

            Tree tree = new Tree();

            tree.Build(input);
            Dictionary<char, byte> dict = MakeDictionary(input);
            BitArray encoded = tree.Encode(input);
            PutIntoFile(encoded, dict);
        }
    }
}