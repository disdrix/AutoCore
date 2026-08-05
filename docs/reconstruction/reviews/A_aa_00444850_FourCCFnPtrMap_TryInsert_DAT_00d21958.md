# Review A (reconstruction fidelity): `aa_00444850` FourCCFnPtrMap_TryInsert_DAT_00d21958

| Field | Value |
|---|---|
| **Stable ID** | `aa_00444850` |
| **VA** | `0x00444850`–`0x00444874` exclusive (**36 B**) |
| **Canonical name** | `FourCCFnPtrMap_TryInsert_DAT_00d21958` |
| **Ghidra name** | `FUN_00444850` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-H) |
| **Counterpart** | `reviews/B_aa_00444850_FourCCFnPtrMap_TryInsert_DAT_00d21958.md` |
| **System** | Palantir FourCC→fn* global map wrapper |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (36 B body + call sites `@00754820`). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin wrapper: pack register **FourCC tag (EAX)** + **handler pointer (ECX)** as a key/value pair, run tree-map find/insert on **`DAT_00d21958`** via `FUN_00458510`, discard out-pair. Palantir device start registers `'EFCT'` and `'MRPH'`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-H append) | `docs/reconstruction/raw/aa_00444850_FUN_00444850.md` |
| Annotated | `docs/reconstruction/raw/aa_00444850_FUN_00444850.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FourCCFnPtrMap_TryInsert_DAT_00d21958.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00444850.cpp` |
| Function records | `functions/aa_00444850_FUN_00444850.md`, `functions/aa_00444850_FourCCFnPtrMap_TryInsert_DAT_00d21958.md` |
| Live | body hex + `FUN_00754680` site bytes |

---

## 3. Signature (sealed)

```c
// EAX=tag; ECX=handler*; bare RET; void
void FourCCFnPtrMap_TryInsert_DAT_00d21958(
    /*eax*/ uint32_t tag,
    /*ecx*/ void* handler);
```

| Formal | Source | Conf |
|---|---|---|
| tag | EAX (saved then key dword); callers load FourCC immediates | **High** |
| handler | ECX staged as key+4; callers load code ptr immediates | **High** |
| map | `MOV EAX,0x00d21958` before call | **High** |
| cleanup | bare `C3` | **High** |

---

## 4. Control flow (bytes authority)

```
SUB ESP,0x10; PUSH EBX
stage out-pair; key.tag=EAX; key.handler=ECX
EBX=&key; EAX=&DAT_00d21958
CALL FUN_00458510(out)
POP EBX; ADD ESP,0x10; RET
```

| Stage | Match | Conf |
|---|---|---|
| Register formals | caller sites + body stores | **High** |
| Map global | immediate `B8 58 19 D2 00` | **High** |
| Single callee | `E8`→`00458510` | **High** |
| Discard out | no use after call | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 36 B hex — raw W35-H append.  
`83 EC 10 53 … B8 58 19 D2 00 … E8 A1 3C 01 00 5B 83 C4 10 C3`  
Pad `CC` then `FUN_00444880`.

**Decompile ≢ bytes** on formals (void/no-arg). **Bytes + call sites win.**

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | wrapper |
| Callers | `FUN_00754680` ×2 (`'EFCT'`, `'MRPH'`) |
| Callees | `FUN_00458510` |
| Sibling | `FUN_00444880` → `DAT_00d21964` |

---

## 7. Gaps

1. Unowned full contract of `FUN_00458510` / insert node.  
2. Update-vs-ignore on existing key.  
3. Product English for map / handlers.  
4. Runtime / bit-exact.

---

## 8. Verdict

**accept-with-gaps** — wrapper ABI + map identity + FourCC call-site tags sealed High; callee tree residual only.
