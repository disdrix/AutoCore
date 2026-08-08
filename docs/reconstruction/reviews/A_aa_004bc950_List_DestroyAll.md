# Review A (reconstruction fidelity): `aa_004bc950` List_DestroyAll

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bc950` |
| **VA** | `0x004bc950`–`0x004bca4a` (**251 B** / `0xFB`) |
| **Canonical name** | `List_DestroyAll` |
| **Ghidra name** | `FUN_004bc950` |
| **Review date** | `2026-08-05` (R10-028 dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY R10-028) |
| **Counterpart** | `reviews/B_aa_004bc950_List_DestroyAll.md` |
| **System** | client::list / inventory-transfer |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 251 B) + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + product SEH string |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher. No parent ledgers.

---

## 1. Purpose

CS-guarded list **DestroyAll**: refuse when TraversalLock flag held (`throw 0x80070005`); else scalar-delete every node on head `+0x1c` and zero heads `+0x1c/+0x20/+0x24`. Product English from SEH string.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004bc950_FUN_004bc950.md` (+ R10-028 append + full hex) |
| Annotated | `docs/reconstruction/raw/aa_004bc950_FUN_004bc950.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/List_DestroyAll.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bc950.cpp` |
| Function records | `aa_004bc950_FUN_004bc950.md`, `aa_004bc950_List_DestroyAll.md` |
| Live | decompile ≡ raw main CF; full 251 B hex; product string `@0x00a33af0` |
| Family | `List_RemoveAll` `0x004bc580`, `List_TraversalLock` `0x004294f0`, `List_IterateNext` `0x004022a0` |
| CF twin (other VA) | `ObjectCsList_DestroyAll_Inferred` `0x00424060` — same plate; **do not merge** |

---

## 3. Signature (sealed)

```c
// ECX = list host; void; bare RET (C3)
void __fastcall List_DestroyAll(void *listHost);
```

| Slot | Source | Conf |
|---|---|---|
| listHost | ECX → ESI (`8B F1`) | **High** |
| CS | `host+4` | **High** |
| head | `host+0x1c`; node next `+8` | **High** |
| lock flag | `host+0x28` | **High** |
| throw | `0x80070005` when locked | **High** |
| RET | `C3` | **High** |
| node[+4] clear | **absent** (vs RemoveAll) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
EnterCS(host+4)
if (host[+0x28]) { LeaveCS; throw 0x80070005 }
while (node = head) {
  head = node[+8]; (*vtbl)(node, 1)
}
host[+0x24]=host[+0x20]=host[+0x1c]=0
LeaveCS
```

| Stage | Match | Conf |
|---|---|---|
| ECX formal + Enter/Leave CS | **Yes** | **High** |
| Lock flag gate + E_ACCESSDENIED | **Yes** | **High** |
| Drain + scalar dtor(1) without node[+4] clear | **Yes** | **High** |
| Zero three heads | **Yes** | **High** |
| Product string DestroyAll | **Yes** (`0x00a33af0`) | **High** |
| SEH landing ≠ main CF | **Yes** (decompiler omits correctly) | **High** |
| Product class English | open | **Low** |

---

## 5. Callers (evidence)

| Caller | Sites | Notes |
|---|---|---|
| `FUN_004bcab0` | 1 | Scalar dtor; DestroyAll then DeleteCS |
| `FUN_004bcbc0` | 2 | Complete dtor dual-vtbl drain |
| `FUN_005737c0` | 2 | Complete dtor dual-vtbl drain |
| `FUN_00572730` | 4 | Inventory grid sort/repack stack-local teardown |

---

## 6. Gaps / open

1. Product C++ class of list host / node payload across callers.
2. Exact meaning of `+0x20`/`+0x24` beyond “cleared with head”.
3. Runtime / bit-exact / differential.

**Verdict:** **accept** — ABI/CF/string/family sealed; residual product type names only (does not block role seal).
