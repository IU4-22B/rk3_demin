#include <stdlib.h>
#include <stdio.h>
struct ListNode {
	struct ListNode* next;
	int value;
};
typedef struct ListNode* LNode;
LNode get(LNode listNode, unsigned index) {
	if (listNode == NULL) {
		return NULL;
	}
	else if (index == 0) {
		return listNode;
	}
	else {
		return get(listNode->next, index - 1);
	}
}
LNode get_pos_value(LNode listNode, unsigned value) {
	if (listNode == NULL) return NULL;
	if ((listNode->value) == value) {
		return listNode;
	}
	else {
		return get_pos_value(listNode->next, value);
	}
}
LNode construct_node(int value) {
	LNode new_node = (LNode)malloc(sizeof(struct ListNode));
	new_node->value = value;
	new_node->next = NULL;
	return new_node;
}
LNode add_node_to_list(LNode list_node, int value) {
	LNode new_node = construct_node(value);
	list_node->next = new_node;
	return new_node;
}
LNode find_even(LNode list_node) {
	while (list_node != NULL) {
		if (!(list_node->value & 1)) return list_node;
		list_node = list_node->next;
	}
	return NULL;
}
LNode delete(LNode list_node, int value) {
	if (list_node == NULL) return NULL;
	unsigned char flag = 0;
	if (get_pos_value(&list_node, value) == NULL) return NULL;
	LNode delete_node = get_pos_value(&list_node, value);
	LNode end_new_list_node, start_new_list_node;
	if (list_node->value != delete_node->value) {

		end_new_list_node = start_new_list_node = construct_node(list_node->value);
		list_node = list_node->next;
	}
	else {
		flag = 1;
		list_node = list_node->next;
		end_new_list_node = start_new_list_node = construct_node(list_node->value);
	}
	while ((list_node->next) != NULL) {
		if (list_node->value != delete_node->value || flag == 1) {
			end_new_list_node = add_node_to_list(end_new_list_node, list_node->value);
			list_node = list_node->next;
		}
		else {
			flag = 1;
			list_node = list_node->next;
		}
	}
	if (list_node->value != delete_node->value || flag == 1) {
		end_new_list_node = add_node_to_list(end_new_list_node, list_node->value);
	}
	return start_new_list_node;
}
void print(LNode list_node) {
	if (list_node == NULL) return;
	if ((list_node->next) != NULL) {
		printf("%d,", list_node->value);
	}
	else {
		printf("%d", list_node->value);
	}

	print(list_node->next);
}
unsigned size(LNode list_node) {
	unsigned count = 0;
	while ((list_node = list_node->next) != NULL) {
		count++;
	}
	count++;
	return count;

}
LNode append(LNode listNode, int value) {
	LNode end_new_list_node, start_new_list_node;
	if (listNode == NULL) return NULL;
	else {
		end_new_list_node = start_new_list_node = construct_node(listNode->value);
		listNode = listNode->next;
		while ((listNode->next) != NULL) {
			end_new_list_node = add_node_to_list(end_new_list_node, listNode->value);
			listNode = listNode->next;
		}
		end_new_list_node = add_node_to_list(end_new_list_node, value);
		return start_new_list_node;
	}
}
LNode reversed(LNode listNode) {
	struct ListNode* previous = NULL;
	struct ListNode* curren = listNode;
	while (curren != NULL) {
		listNode = listNode->next;
		curren->next = previous;
		previous = curren;
		curren = listNode;
	}
	return previous;
}
LNode copy(LNode listNode) {
	LNode end_new_list_node, start_new_list_node;
	if (listNode == NULL) return NULL;
	else {
		end_new_list_node = start_new_list_node = construct_node(listNode->value);
		listNode = listNode->next;
		while ((listNode->next) != NULL) {
			end_new_list_node = add_node_to_list(end_new_list_node, listNode->value);
			listNode = listNode->next;
		}
		end_new_list_node = add_node_to_list(end_new_list_node, listNode->value);
		return start_new_list_node;
	}

}

LNode even(LNode listNode) {
	LNode end_new_list_node, start_new_list_node;
	listNode = find_even(listNode);

	if (listNode == NULL) return NULL;
	else {
		end_new_list_node = start_new_list_node = construct_node(listNode->value);
		listNode = listNode->next;
		while ((listNode = find_even(listNode)) != NULL) {
			end_new_list_node = add_node_to_list(end_new_list_node, listNode->value);
			listNode = listNode->next;
		}
		return start_new_list_node;
	}
}

int main() {
	struct ListNode l1, l2, l3, l4, l5, l6, l7, l8; LNode even_list, got, del, copy1, copy2, reversed_node;
	l1.value = 1; l1.next = &l2;
	l2.value = 2; l2.next = &l3;
	l3.value = 3; l3.next = &l4;
	l4.value = 4; l4.next = &l5;
	l5.value = 5; l5.next = &l6;
	l6.value = 6; l6.next = &l7;
	l7.value = 5; l7.next = &l8;
	l8.value = 7; l8.next = NULL;
	int delete_num = 5;
	printf("l1\n");
	print(&l1);
	copy1 = copy(&l1);
	copy2 = copy(&l1);
	printf(" SIZE %d\n", size(&l1));
	printf("DEL %d \n", delete_num);
	del = delete(&l1, delete_num);
	print(del);
	printf("\nORIGINAL\n");
	print(copy1);
	printf("\nPLUS\n");
	copy2 = append(copy2, 15);

	print(copy2);
	printf("REVERS \n");
	reversed_node = reversed(copy1);
	print(reversed_node);
	getchar();
}