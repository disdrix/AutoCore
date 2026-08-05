# Review A (reconstruction fidelity): `aa_004e3610` CNDHash_Remove_009cc1f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e3610` |
| **VA** | `0x004e3610`–`0x004e36d7` (**200 B**) |
| **Canonical name** | `CNDHash_Remove_009cc1f0` |
| **Ghidra name** | `FUN_004e3610` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-K) |
| **Counterpart** | `reviews/B_aa_004e3610_CNDHash_Remove_009cc1f0.md` |
| **System** | container / CNDHash |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (200 B) + `get_assembly_context` @ caller `0x004d65c8`. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

**CNDHash remove(key, outValue*)** on the node-vtbl family `PTR_FUN_009cc1f0`:

1. Optional out zeroed first.
2. Traversal lock `hash+0x1d` → warn strings; **do not abort**.
3. Bucket index + `FUN_004e2ca0` find/bucket-unlink.
4. Miss → `0x80004005`; hit → transfer value @ `node+0x08`, ordered-list unlink, freelist push, `count--`, return `0`.

Sector map dtor drains this hash by remove-then-delete-value.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W27-K) | `docs/reconstruction/raw/aa_004e3610_FUN_004e3610.md` |
| Annotated | `docs/reconstruction/raw/aa_004e3610_FUN_004e3610.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004e3610.cpp` |
| Clean named | `docs/reconstruction/reconstructed-exact/CNDHash_Remove_009cc1f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e3610_FUN_004e3610.md` |
| Family twins | `CNDHash_Remove` `0x00538b20`; `CNDHash_Remove_u64` `0x00413a60` |
| Live | decompile ≡ raw CF; full body hex; RET 8 epilogues |

---

## 3. Signature (sealed)

```c
// ECX = hash*; stack key, void **outOpt; RET 8; EAX 0 | E_FAIL
uint32_t __thiscall CNDHash_Remove_009cc1f0(void *hash, uint32_t key, void **outOpt);
```

| Formal | Source | Conf |
|---|---|---|
| hash | ECX | **High** |
| key | Stack[0x4] | **High** |
| outOpt | Stack[0x8] | **High** |
| return | EAX | **High** |
| cleanup | `RET 8` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if out: *out = 0
if lock[0x1d]: log remove+VOG_DEBUG_STOP
node = find+bucket_unlink(key)   // FUN_004e2ca0 after mask index
if !node: return E_FAIL
if out: *out = node.value; node.value = 0
unlink ordered list (head+0x14 / tail+0x18)
node.vtbl = 009cc1f0; maybe delete residual value; value=0
freelist push @ hash+0x20; count--; return 0
```

| Stage | Match | Conf |
|---|---|---|
| Out zero + lock warn-only | **Yes** | **High** |
| Bucket index + FUN_004e2ca0 | **Yes** (bytes) | **High** |
| Miss E_FAIL / hit 0 | **Yes** | **High** |
| Value transfer then clear | **Yes** | **High** |
| List unlink + freelist | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Entry | `55 8B 6C 24 0C` … out-zero / lock test |
| String pushes | `68 C0 4B A6 00` → `0x00a64bc0` HashError:remove…; `68 44 58 A1 00` → VOG_DEBUG_STOP |
| Vtbl store | `C7 06 F0 C1 9C 00` → `0x009cc1f0` |
| Success epilogue | `5F 5E 33 C0 5D C2 08 00` |
| Fail epilogue | `5F 5E B8 05 40 00 80 5D C2 08 00` |
| Full body | 200 B @ `0x004e3610` |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product English beyond CNDHash / HashError family.
- Whether any caller uses null out (payload free path) — sector map always passes out.
- Runtime differential — open.

---

## 7. Verdict

**accept** — ABI, CF, transfer policy, freelist, and HRESULT returns sealed against live decompile + full body bytes; family-consistent with sealed remove twins.
