package unitn.minecraft.data;

import javafx.scene.control.cell.CheckBoxListCell;

public class Map {
    Block[][] blocks;
    int size;

    public Map() {
        this.size = 9;
        blocks = new Block[this.size][this.size];

        for (int i = 0; i < this.size; i++) {
            for (int j = 0; j < this.size; j++) {
                this.blocks[i][j] = new Block();
            }
        }
    }

    public void display_on_out() {
        for (int i = 0; i < this.size * 5; i++) {
            System.out.print("-");
        }
        System.out.println();

        for (int i = 0; i < this.size; i++) {
            for (int j = 0; j < this.size; j++) {
                System.out.print(" [" + this.blocks[i][j].Display() + "] ");
            }
            System.out.println();
        }

        for (int i = 0; i < this.size * 5; i++) {
            System.out.print("-");
        }
        System.out.println();
    }

    public void change_cell(int i, int j) {
        if (i >= 0 && i < this.size && j >= 0 && j < this.size) {
            this.blocks[i][j] = new Block('A');
        }
    }

    private void swap(int i, int j) {
        Block tmp = this.blocks[i][j];
        this.blocks[i][j] = this.blocks[i+1][j];
        this.blocks[i+1][j] = tmp;
    }

    public void insert_at_coords_rec(int i, int j, Block block) {
        if (i == (this.size - 1)) {
            return;
        } else if (!block.falls_with_gravity()) {
            return;
        } else if (!this.blocks[i+1][j].blocks_fall_through()) {
            return;
        }

        this.blocks[i][j] = block;
        this.swap(i, j);
        this.insert_at_coords_rec(i+1, j, block);
    }

    public void insert_at_coords_iter(int i, int j, Block block) {
        this.blocks[i][j] = block;
        
        if (!block.falls_with_gravity()) {
            return;
        }

        while (true) {
            if (i == this.size) {
                break;
            } else if (!this.blocks[i + 1][j].blocks_fall_through()) {
                break;
            }

            this.swap(i, j);
            i += 1;
        }
    }
}
