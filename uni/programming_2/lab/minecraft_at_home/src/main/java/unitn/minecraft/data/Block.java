package unitn.minecraft.data;

public class Block {
    private char content;
    private boolean falls_with_gravity;
    private boolean blocks_fall_through;

    public Block() {
        this.content = '-';
        this.falls_with_gravity = false;
        this.blocks_fall_through = true;
    }

    public Block(char content) {
        this.content = content;
        this.falls_with_gravity = true;
        this.blocks_fall_through = false;
    }

    public boolean falls_with_gravity() {
        return falls_with_gravity;
    }

    public boolean blocks_fall_through() {
        return blocks_fall_through;
    }

    char Display() {
        return content;
    }
}
