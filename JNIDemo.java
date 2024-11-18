public class JNIDemo {
    static {
        // 加载本地库
        System.loadLibrary("JNIDemo");

    }
    public native void allocateMemory(int sizeInBytes);

    public static void main(String[] args) throws InterruptedException  {
        JNIDemo leak = new JNIDemo();
        for (int i = 0; i < 100; i++) {
            leak.allocateMemory(1000 * 1024 * 1024); // 每次分配 10 MB
            System.out.println("Allocated 10 MB native memory, iteration: " + (i + 1));
            Thread.sleep(2000); // 每次等待 0.5 秒，便于观察
        }
        System.out.println("Finished allocating memory. Monitor with tools!");

    }
}
