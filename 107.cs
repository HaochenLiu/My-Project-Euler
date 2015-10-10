using System;
using System.Diagnostics;
using System.IO;
using System.Collections.Generic;

namespace euler
{
    class Problem107
    {
        public static void Main(string[] args)
        {
            string filename = Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory) + "\\input.txt";
            new Problem107().MinimalSpanningTree(filename);
        }

        public void MinimalSpanningTree(string filename)
        {
            Stopwatch clock = Stopwatch.StartNew();

            //Read the input file
            string[] lines = File.ReadAllLines(filename);

            //create a forest F (a set of trees),
            //where each vertex in the graph is a separate tree
            int N = lines[0].Split(',').Length;
            DisjointSet vertices = new DisjointSet(N);

            //create a set S containing all the edges in the graph
            //The tuple contains weight,vertex, vertex
            List<Tuple<int, int, int>> edges = new List<Tuple<int, int, int>>();
            int initialWeight = 0;

            for (int i = 0; i < N; i++)
            {
                string[] edge = lines[i].Split(',');

                for (int j = 0; j < i; j++)
                {
                    if (edge[j] != "-")
                    {
                        int weight = Convert.ToInt32(edge[j]);
                        edges.Add(new Tuple<int, int, int>(weight, i, j));
                        initialWeight += weight;
                    }
                }
            }

            //Sort edges to have the minimum weight at top
            edges.Sort();
            int k = 0;
            //while S is nonempty and F is not yet spanning
            int minSpanningTreeWeight = 0;
            while (!vertices.isSpanning())
            {
                //remove an edge with minimum weight from S
                //Since we have a sorted list we just go through the list

                //if that edge connects two different trees, then add it to the forest,
                //combining two trees into a single tree
                if (vertices.Find(edges[k].Item2) != vertices.Find(edges[k].Item3))
                {
                    vertices.Union(edges[k].Item2, edges[k].Item3);
                    minSpanningTreeWeight += edges[k].Item1;
                }
                k++;
            }

            clock.Stop();
            Console.WriteLine("The saving is {0} ", initialWeight - minSpanningTreeWeight);
            Console.WriteLine("Solution took {0} ms", clock.Elapsed.TotalMilliseconds);
        }

        public class DisjointSet
        {
            /// <summary>
            /// The number of elements in the universe.
            /// </summary>
            public int Count { get; private set; }

            /// <summary>
            /// The parent of each element in the universe.
            /// </summary>
            private int[] Parent;

            /// <summary>
            /// Initializes a new Disjoint-Set data structure, with the specified amount of elements in the universe.
            /// </summary>
            /// <param name='count'>
            /// The number of elements in the universe.
            /// </param>
            public DisjointSet(int count)
            {
                this.Count = count;
                this.Parent = new int[this.Count];

                for (int i = 0; i < this.Count; i++)
                    this.Parent[i] = i;
            }

            /// <summary>
            /// Find the parent of the specified element.
            /// </summary>
            /// <param name='i'>
            /// The specified element.
            /// </param>
            /// <remarks>
            /// All elements with the same parent are in the same set.
            /// </remarks>
            public int Find(int i)
            {
                if (this.Parent[i] == i)
                {
                    return i;
                }
                else
                {
                    // Recursively find the real parent of i, and then cache it for later lookups.
                    this.Parent[i] = this.Find(this.Parent[i]);
                    return this.Parent[i];
                }
            }

            /// <summary>
            /// Union the sets that the specified elements belong to.
            /// </summary>
            /// <param name='i'>
            /// The first element.
            /// </param>
            /// <param name='j'>
            /// The second element.
            /// </param>
            public void Union(int i, int j)
            {
                this.Parent[this.Find(i)] = this.Find(j);
            }

            public bool isSpanning()
            {
                for (int i = 1; i < this.Count; i++)
                {
                    if (Find(0) != Find(i)) return false;
                }
                return true;
            }
        }
    }
}
