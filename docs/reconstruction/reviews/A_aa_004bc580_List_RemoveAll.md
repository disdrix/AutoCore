# Review A (reconstruction fidelity): `aa_004bc580` List_RemoveAll

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc580` |
| **VA** | `0x004bc580`–`0x004bc67b` (**252 B**) |
| **Canonical name** | `List_RemoveAll` |
| **Ghidra name** | `FUN_004bc580` |
| **Review date** | `2026-08-04` (W37-U dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-U) |
| **Counterpart** | `reviews/B_aa_004bc580_List_RemoveAll.md` |
| **System** | client::list |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 252 B) + `analyze_function_complete` + `get_function_by_address` + xrefs + sibling decompile (`List_TraversalLock`) |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

CS-guarded list RemoveAll: refuse when TraversalLock flag held (`throw 0x80070005`); else scalar-delete every node on head `+0x1c` and zero heads `+0x1c/+0x20/+0x24`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004bc580_FUN_004bc580.md` (+ W37-U append + full hex) |
| Annotated | `docs/reconstruction/raw/aa_004bc580_FUN_004bc580.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/List_RemoveAll.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bc580.cpp` |
| Function records | `aa_004bc580_FUN_004bc580.md`, `aa_004bc580_List_RemoveAll.md` |
| Live | decompile ≡ raw main CF; full 252 B hex; product string `@0x00a467ec` |
| Family | `List_TraversalLock` `0x004294f0`, `List_IterateNext` `0x004022a0` (NAMING_REGISTRY) |

---

## 3. Signature (sealed)

```c
// ECX = list host; void; bare RET (C3)
void __fastcall List_RemoveAll(void *listHost);
```

| Slot | Source | Conf |
|---|---|---|
| listHost | ECX → ESI (`8B F1`) | **High** |
| CS | `host+4` | **High** |
| head | `host+0x1c`; node next `+8` | **High** |
| lock flag | `host+0x28` | **High** |
| throw | `0x80070005` when locked | **High** |
| RET | `C3` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
EnterCS(host+4)
if (host[+0x28]) { LeaveCS; throw 0x80070005 }
while (node = head) {
  head = node[+8]; node[+4]=0; (*vtbl)(node, 1)
}
host[+0x24]=host[+0x20]=host[+0x1c]=0
LeaveCS
```

| Stage | Match | Conf |
|---|---|---|
| ECX formal + Enter/Leave CS | **Yes** | **High** |
| Lock flag gate + E_ACCESSDENIED | **Yes** | **High** |
| Drain + scalar dtor(1) | **Yes** | **High** |
| Zero three heads | **Yes** | **High** |
| Product string RemoveAll | **Yes** (`0x00a467ec`) | **High** |
| SEH landing ≠ main CF | **Yes** (decompiler omits correctly) | **High** |
| Product class English | open | **Low** |

---

## 5. Gaps / open

1. Product C++ class of list host / node payload across callers.
2. Exact meaning of `+0x20`/`+0x24` beyond “cleared with head” (drain walks only `+0x1c`).
3. Runtime / bit-exact / differential.

**Verdict:** **accept** — ABI/CF/string/family sealed; residual product type names only (does not block role seal).
