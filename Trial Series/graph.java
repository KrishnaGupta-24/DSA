import java.util.*;

public class BFS_disjoint{
    static class Edge{
        int src;
        int dest;
        int wt;

        public Edge(int s, int d, int w){
            this.src=s;
            this.dest=d;
            this.wt=w;
        }
    }
    static void createGraph(ArrayList<Edge> graph[]){
       Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int V = sc.nextInt();

        ArrayList<Edge>[] graph = new ArrayList[V];
        for (int i = 0; i < V; i++) {
            graph[i] = new ArrayList<>();
        }

        System.out.print("Enter number of edges: ");
        int E = sc.nextInt();

        System.out.println("Enter edges in the format: source destination weight");
        for (int i = 0; i < E; i++) {
            int src = sc.nextInt();
            int dest = sc.nextInt();
            int wt = sc.nextInt();

            graph[src].add(new Edge(src, dest, wt));
            // If it's an undirected graph, also add the reverse edge:
            graph[dest].add(new Edge(dest, src, wt));
        }
    }

    public static void bfs(ArrayList<Edge>[] graph){
        boolean vis[] = new boolean[graph.length];
        for(int i=0;i<graph.length;i++){
            if(!vis[i]){
                bfsUtil(graph, vis);
            }
        }
    }

    public static void bfsUtil(ArrayList<Edge>[] graph, boolean vis[]){
        Queue<Integer> q = new LinkedList<>();
        boolean vis[] = new boolean[graph.length];
        q.add(0);  //source = 0

        while(!q.isEmpty()){
            int curr = q.remove();

            if(!vis[curr]){   //visit curr
                System.out.print(curr+" ");
                vis[curr] = true;
                for(int i=0;i<graph[curr].size(); i++){  // neighbour visit
                    Edge e = graph[curr].get(i);
                    q.add(e.dest);
                }
            }
        }
    }
    public static void main(String args[]){
        int V = 7;
        ArrayList<Edge> graph[] = new ArrayList[V];
        createGraph(graph);
        bfs(graph);
    }
}