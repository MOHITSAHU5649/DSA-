
    /*
 * Java_Collections_Examples.java
 * Comprehensive examples demonstrating Java Collection Framework usage.
 * Contains demo methods for Lists, Sets, Queues, Maps, Iterators, Comparators,
 * Collections utilities, synchronized and concurrent collections, and custom objects.
 *
 * Run: javac Java_Collections_Examples.java && java Java_Collections_Examples
 * (This single file contains multiple demo methods called from main.)
 */

import java.util.*;
import java.util.concurrent.*;

public class allcollection{

    public static void main(String[] args) {
        System.out.println("--- Java Collections Framework Examples ---\n");

        demoListImplementations();
        demoSetImplementations();
        demoQueueDeque();
        demoMapImplementations();
        demoIteratorsAndListIterators();
        demoSortingAndComparators();
        demoCollectionsUtilities();
        demoSynchronizedAndConcurrent();
        demoCustomObjectInCollections();
        demoPriorityQueueWithComparator();
        demoArrayDequeAsStackAndQueue();

        System.out.println("\n--- End of demos ---");
    }

    // ---------------------- Lists ----------------------
    static void demoListImplementations() {
        System.out.println("1) List implementations: ArrayList, LinkedList, Vector, Stack\n");

        List<String> arrayList = new ArrayList<>();
        arrayList.add("apple");
        arrayList.add("banana");
        arrayList.add("cherry");
        System.out.println("ArrayList: " + arrayList);

        List<String> linkedList = new LinkedList<>(arrayList);
        ((LinkedList<String>) linkedList).addFirst("zero");
        System.out.println("LinkedList (after addFirst): " + linkedList);

        Vector<String> vector = new Vector<>(arrayList);
        vector.add("date");
        System.out.println("Vector: " + vector);

        Stack<String> stack = new Stack<>();
        stack.push("one");
        stack.push("two");
        System.out.println("Stack peek: " + stack.peek());
        System.out.println("Stack pop: " + stack.pop());
        System.out.println("Stack now: " + stack);

        System.out.println();
    }

    // ---------------------- Sets ----------------------
    static void demoSetImplementations() {
        System.out.println("2) Set implementations: HashSet, LinkedHashSet, TreeSet\n");

        Set<Integer> hashSet = new HashSet<>();
        hashSet.add(3);
        hashSet.add(1);
        hashSet.add(2);
        hashSet.add(2); // duplicate ignored
        System.out.println("HashSet (no order guaranteed): " + hashSet);

        Set<Integer> linked = new LinkedHashSet<>();
        linked.add(3);
        linked.add(1);
        linked.add(2);
        System.out.println("LinkedHashSet (insertion order): " + linked);

        Set<Integer> tree = new TreeSet<>();
        tree.add(5);
        tree.add(2);
        tree.add(9);
        System.out.println("TreeSet (sorted order): " + tree);

        System.out.println();
    }

    // ---------------------- Queue / Deque ----------------------
    static void demoQueueDeque() {
        System.out.println("3) Queues and Deques: PriorityQueue, ArrayDeque\n");

        Queue<String> pq = new PriorityQueue<>();
        pq.add("pear");
        pq.add("apple");
        pq.add("orange");
        System.out.println("PriorityQueue (natural order on poll):");
        while (!pq.isEmpty()) {
            System.out.print(pq.poll() + " ");
        }
        System.out.println("\n");

        Deque<String> deque = new ArrayDeque<>();
        deque.add("first");
        deque.addLast("second");
        deque.addFirst("zero");
        System.out.println("ArrayDeque as deque: " + deque);

        System.out.println();
    }

    // ---------------------- Maps ----------------------
    static void demoMapImplementations() {
        System.out.println("4) Map implementations: HashMap, LinkedHashMap, TreeMap, Hashtable\n");

        Map<String, Integer> hashMap = new HashMap<>();
        hashMap.put("Alice", 30);
        hashMap.put("Bob", 25);
        hashMap.put(null, 99); // HashMap allows null key
        System.out.println("HashMap: " + hashMap);

        Map<String, Integer> linkedMap = new LinkedHashMap<>();
        linkedMap.put("Alice", 30);
        linkedMap.put("Bob", 25);
        System.out.println("LinkedHashMap (insertion order): " + linkedMap);

        Map<String, Integer> treeMap = new TreeMap<>();
        treeMap.putAll(linkedMap);
        System.out.println("TreeMap (sorted by key): " + treeMap);

        Map<String, Integer> table = new Hashtable<>();
        table.put("X", 1);
        table.put("Y", 2);
        System.out.println("Hashtable (legacy, synchronized): " + table);

        System.out.println();
    }

    // ---------------------- Iterators ----------------------
    static void demoIteratorsAndListIterators() {
        System.out.println("5) Iterator and ListIterator examples\n");

        List<String> list = new ArrayList<>(Arrays.asList("a", "b", "c", "d"));
        Iterator<String> it = list.iterator();
        System.out.print("Iterator removal while iterating: ");
        while (it.hasNext()) {
            String s = it.next();
            if (s.equals("b")) {
                it.remove();
            } else {
                System.out.print(s + " ");
            }
        }
        System.out.println("\nAfter removal: " + list);

        ListIterator<String> lit = list.listIterator();
        System.out.print("ListIterator forward: ");
        while (lit.hasNext()) {
            System.out.print(lit.next() + " ");
        }
        System.out.print("\nListIterator backward: ");
        while (lit.hasPrevious()) {
            System.out.print(lit.previous() + " ");
        }

        System.out.println("\n");
    }

    // ---------------------- Sorting & Comparators ----------------------
    static void demoSortingAndComparators() {
        System.out.println("6) Sorting Lists and using Comparators\n");

        List<String> fruits = new ArrayList<>(Arrays.asList("apple", "orange", "banana", "pear"));
        Collections.sort(fruits); // natural order
        System.out.println("Sorted fruits (natural): " + fruits);

        // custom comparator: sort by length then lexicographically
        fruits.sort(Comparator.comparingInt(String::length).thenComparing(Comparator.naturalOrder()));
        System.out.println("Sorted by length then lexicographically: " + fruits);

        // sorting maps by values
        Map<String, Integer> map = new HashMap<>();
        map.put("a", 3);
        map.put("b", 1);
        map.put("c", 2);
        List<Map.Entry<String, Integer>> entries = new ArrayList<>(map.entrySet());
        entries.sort(Map.Entry.comparingByValue());
        System.out.println("Map entries sorted by value: " + entries);

        System.out.println();
    }

    // ---------------------- Collections utilities ----------------------
    static void demoCollectionsUtilities() {
        System.out.println("7) Collections utility methods (reverse, fill, copy, unmodifiable etc.)\n");

        List<Integer> numbers = new ArrayList<>(Arrays.asList(5, 3, 8, 1));
        Collections.sort(numbers);
        System.out.println("Sorted numbers: " + numbers);

        Collections.reverse(numbers);
        System.out.println("Reversed: " + numbers);

        List<Integer> src = Arrays.asList(1,2,3,4);
        List<Integer> dest = new ArrayList<>(Arrays.asList(0,0,0,0));
        Collections.copy(dest, src); // dest must be at least as big as src
        System.out.println("After copy, dest: " + dest);

        List<String> readOnly = Collections.unmodifiableList(Arrays.asList("x","y"));
        System.out.println("Unmodifiable list (read-only): " + readOnly);

        Map<String, String> singleton = Collections.singletonMap("k","v");
        System.out.println("Singleton map: " + singleton);

        System.out.println();
    }

    // ---------------------- Synchronized and Concurrent ----------------------
    static void demoSynchronizedAndConcurrent() {
        System.out.println("8) Synchronized wrappers and concurrent collections\n");

        List<String> normal = new ArrayList<>();
        List<String> syncList = Collections.synchronizedList(normal);
        syncList.add("one");
        syncList.add("two");
        System.out.println("SynchronizedList: " + syncList);

        // ConcurrentHashMap example
        ConcurrentMap<String, Integer> cmap = new ConcurrentHashMap<>();
        cmap.put("A", 1);
        cmap.put("B", 2);
        cmap.computeIfAbsent("C", k -> 3);
        System.out.println("ConcurrentHashMap: " + cmap);

        // CopyOnWriteArrayList
        CopyOnWriteArrayList<String> cow = new CopyOnWriteArrayList<>();
        cow.add("alpha");
        cow.add("beta");
        System.out.println("CopyOnWriteArrayList: " + cow);

        System.out.println();
    }

    // ---------------------- Custom object in collections ----------------------
    static void demoCustomObjectInCollections() {
        System.out.println("9) Custom object in collections: equals(), hashCode(), Comparable\n");

        // Person implements equals & hashCode
        Set<Person> people = new HashSet<>();
        people.add(new Person("Alice", 30));
        people.add(new Person("Bob", 25));
        people.add(new Person("Alice", 30)); // duplicate as per equals -> ignored
        System.out.println("HashSet of Person (duplicates removed): " + people);

        // TreeSet requires Comparable or Comparator
        Set<Person> sorted = new TreeSet<>();
        sorted.addAll(people);
        System.out.println("TreeSet of Person (sorted by age then name): " + sorted);

        System.out.println();
    }

    static void demoPriorityQueueWithComparator() {
        System.out.println("10) PriorityQueue with custom Comparator\n");

        PriorityQueue<Person> pqueue = new PriorityQueue<>(Comparator.comparingInt(p -> p.age));
        pqueue.add(new Person("Zara", 40));
        pqueue.add(new Person("Mike", 22));
        pqueue.add(new Person("John", 35));
        System.out.print("Poll persons by ascending age: ");
        //while (!pqueue.isEmpty()) System.out.print(pqueue.poll().name + "(" + pqueue.peekNameAge() + ") ");
         while (!pqueue.isEmpty()) {
            Person p = pqueue.poll(); // get and remove head
            System.out.print(p.name + "(" + p.age + ") ");
        }
        
        System.out.println("\n");
    }

    static void demoArrayDequeAsStackAndQueue() {
        System.out.println("11) ArrayDeque as Stack and Queue\n");

        ArrayDeque<Integer> ad = new ArrayDeque<>();
        // as queue
        ad.offer(1); ad.offer(2); ad.offer(3);
        System.out.println("ArrayDeque as queue (poll): " + ad.poll());
        // as stack
        ad.push(10); ad.push(20);
        System.out.println("ArrayDeque as stack (pop): " + ad.pop());

        System.out.println();
    }

    // ---------------------- Helper classes ----------------------
    static class Person implements Comparable<Person> {
        String name;
        int age;

        Person(String name, int age) { this.name = name; this.age = age; }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Person person = (Person) o;
            return age == person.age && Objects.equals(name, person.name);
        }

        @Override
        public int hashCode() {
            return Objects.hash(name, age);
        }

        @Override
        public String toString() {
            return name + "(" + age + ")";
        }

        @Override
        public int compareTo(Person o) {
            int byAge = Integer.compare(this.age, o.age);
            if (byAge != 0) return byAge;
            return this.name.compareTo(o.name);
        }
    }

}


