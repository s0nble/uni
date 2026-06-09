public class MaxWithTenThreads {
    static class MaxTask implements Runnable {
        private int[] arr;
        private int start;
        private int end;
        private int localMax;

        public MaxTask(int[] arr, int start, int end) {
            this.arr = arr;
            this.start = start;
            this.end = end;
            this.localMax = arr[start];
        }

        public void run() {
            for (int i = start + 1; i < end; i++) {
                if (arr[i] > localMax) {
                    localMax = arr[i];
                }
            }
        }

        public int getLocalMax() {
            return localMax;
        }
    }

    public static void main(String[] args) throws InterruptedException {
        int[] arr = new int[1000];

        for (int i = 0; i < arr.length; i++) {
            arr[i] = i + 1;
        }

        int numberOfThreads = 10;
        int partSize = 100;

        MaxTask[] tasks = new MaxTask[numberOfThreads];
        Thread[] threads = new Thread[numberOfThreads];

        for (int i = 0; i < numberOfThreads; i++) {
            int start = i * partSize;
            int end = start + partSize;

            tasks[i] = new MaxTask(arr, start, end);
            threads[i] = new Thread(tasks[i]);
            threads[i].start();
        }

        for (int i = 0; i < numberOfThreads; i++) {
            threads[i].join();
        }

        int max = tasks[0].getLocalMax();

        for (int i = 1; i < numberOfThreads; i++) {
            if (tasks[i].getLocalMax() > max) {
                max = tasks[i].getLocalMax();
            }
        }

        System.out.println("Maximum value = " + max);
    }
}
