#include <stdlib.h> // malloc()

struct no {
    int dado;
    struct no* direito;
    struct no* esquerdo;
};

struct no* raiz = NULL;

// cabeçalhos das funções utilitárias
struct no* inserirNo(struct no* subraiz, int valor);
struct no* removerNo(struct no* subraiz, int valor);
int pesquisarNo(struct no* subraiz, int valor);
void pre(struct no* subraiz, void (*callback)());
void em(struct no* subraiz, void (*callback)());
void pos(struct no* subraiz, void (*callback)());
struct no* minNo(struct no* subraiz);
struct no* maxNo(struct no* subraiz);

// interface
void a_inserir(int valor) {
    raiz = inserirNo(raiz, valor);
}

void a_remover(int valor) {
    raiz = removerNo(raiz, valor);
}

int a_pesquisar(int valor) {
    return pesquisarNo(raiz, valor);
}

void a_preOrdem(void (*callback)()) {
    pre(raiz, callback);
}

void a_emOrdem(void (*callback)()) {
    em(raiz, callback);
}

void a_posOrdem(void (*callback)()) {
    pos(raiz, callback);
}

struct no* a_min() {
    return minNo(raiz);
}

struct no* a_max() {
    return maxNo(raiz);
}

// implementação das funções utilitárias recursivas
struct no* inserirNo(struct no* subraiz, int valor) {
    if (subraiz == NULL) {
        struct no* novo = malloc(sizeof(struct no));
        novo->dado = valor;
        novo->direito = NULL;
        novo->esquerdo = NULL;
        return novo;
    } else if (valor < subraiz->dado) {
        subraiz->esquerdo = inserirNo(subraiz->esquerdo, valor);
    } else if (valor > subraiz->dado) {
        subraiz->direito = inserirNo(subraiz->direito, valor);
    }
}

struct no* removerNo(struct no* subraiz, int valor) {
    if (valor < subraiz->dado) {
        subraiz->esquerdo = removerNo(subraiz->esquerdo, valor);
    } else if (valor > subraiz->dado) {
        subraiz->direito = removerNo(subraiz->direito, valor);
    } else {
        if (subraiz->direito == NULL && subraiz->esquerdo == NULL) {
            subraiz = NULL;
        } else if (subraiz->direito == NULL) {
            subraiz = subraiz->esquerdo;
        } else if (subraiz->esquerdo == NULL) {
            subraiz = subraiz->direito;
        } else {
            struct no* sucessor = minNo(subraiz->direito);
            subraiz->dado = sucessor->dado;
            subraiz->direito = removerNo(subraiz->direito, sucessor->dado);
        }
    }

    return subraiz;
}

int pesquisarNo(struct no* subraiz, int valor) {
    if (subraiz == NULL) {
        return 0;
    } else if (valor < subraiz->dado) {
        return pesquisarNo(subraiz->esquerdo, valor);
    } else if (valor > subraiz->dado) {
        return pesquisarNo(subraiz->direito, valor);
    } else {
        return 1;
    }
}

void pre(struct no* subraiz, void (*callback)()) {
    if (subraiz == NULL) return;

    callback(subraiz->dado);
    pre(subraiz->esquerdo, callback);
    pre(subraiz->direito, callback);
}

void em(struct no* subraiz, void (*callback)()) {
    if (subraiz == NULL) return;

    em(subraiz->esquerdo, callback);
    callback(subraiz->dado);    
    em(subraiz->direito, callback);
}

void pos(struct no* subraiz, void (*callback)()) {
    if (subraiz == NULL) return;

    pos(subraiz->esquerdo, callback);
    pos(subraiz->direito, callback);
    callback(subraiz->dado);
}

struct no* minNo(struct no* subraiz) {
    if (subraiz->esquerdo == NULL) {
        return subraiz;
    } else {
        return minNo(subraiz->esquerdo);
    }
}

struct no* maxNo(struct no* subraiz) {
    if (subraiz->direito == NULL) {
        return subraiz;
    } else {
        return maxNo(subraiz->direito);
    }
}