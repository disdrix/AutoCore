# Review A (reconstruction fidelity): `aa_00508c00` HandlerTable54_FindById6c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508c00` |
| **VA** | `0x00508c00` |
| **Body** | `0x00508c00`–`0x00508c41` (**66** bytes) |
| **Canonical name** | `HandlerTable54_FindById6c` (inferred) |
| **Ghidra symbol** | `FUN_00508c00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B — W20-R) |
| **Counterpart** | `reviews/B_aa_00508c00_HandlerTable54_FindById6c.md` |
| **System** | status/hook handler tables |
| **Live tools** | `decompile_function`, `read_memory`, `get_function_by_address`, callers/xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf **linear find-by-id** over a pointer table at **`this+0x54`**:

1. Reject `id == -1` and non-positive global count **`DAT_00d02988`**.
2. Walk `table[i]` for `i ∈ [0, DAT_00d02988)`.
3. Match when **`*(int32*)(table[i] + 0x6c) == id`**.
4. Return matching entry pointer, else **null**.

Part of a fixed family of identical helpers with different table slots / count globals. Equip status-hook dual assigns this slot to item-def subtype **0xb** handlers (`Vehicle_ApplyItemStatusHooksOnEquip`).

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw | `raw/aa_00508c00_FUN_00508c00.md` | Live decomp ≡ 2026-07-23; W20-R append |
| Annotated | `raw/aa_00508c00_FUN_00508c00.annotated.md` | Updated |
| Clean | `reconstructed-exact/HandlerTable54_FindById6c.cpp` | New sealed |
| Alias | `reconstructed-exact/FUN_00508c00.cpp` | Updated |
| Function record | `functions/aa_00508c00_FUN_00508c00.md` | Updated |
| Live decompile | Ghidra `0x00508c00` | Match raw |
| Live `read_memory` | 66 B | ABI + loop sealed |
| Body range | `get_function_by_address` | `00508c00`–`00508c41` |
| Callers | Ghidra | 8 functions / 12 call sites |
| Parent dual | `A_aa_004fe380_*` | subtype 0xb consumer |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` ECX=registry, stack id, `ret 4` | **High** | bytes `c2 04 00` both exits |
| Table base `*(this+0x54)` | **High** | `mov esi,[ecx+0x54]` |
| Id field at `entry+0x6c` | **High** | `cmp [ebx+0x6c], edi` |
| Count = `DAT_00d02988` exclusive upper | **High** | `cmp eax,edx` / `jl` |
| Reject `id == -1` | **High** | early exit |
| Leaf (no callees) | **High** | |
| Family twin at `+0x58` = `FUN_00508c50` | **High** | parallel decomp |
| Role for subtype 0xb handlers | **High** | parent dual |
| Product class / entry type names | **Tentative** | inferred structural only |
| Runtime fill of count/table | Open | static BSS zeros |

---

## 4. Control flow seal (`read_memory`)

```text
push edi
mov  edi, [esp+8]           ; id
xor  eax, eax
cmp  edi, -1
jz   → return 0
mov  edx, [DAT_00d02988]
test edx, edx
push ebx / push esi
jle  → return 0 (pops)
mov  esi, [ecx+0x54]        ; table
mov  ecx, esi
loop:
  mov  ebx, [ecx]           ; *entry
  cmp  [ebx+0x6c], edi
  jz   → return table[eax]
  add  eax, 1
  add  ecx, 4
  cmp  eax, edx
  jl   loop
→ return 0
; both success/fail: pop esi/ebx/edi; ret 4
```

Clean ≡ annotated ≡ raw ≡ live decomp ≡ bytes.

---

## 5. Callers

| Function | Role |
|---|---|
| `FUN_004fe380` Vehicle_ApplyItemStatusHooksOnEquip | subtype **0xb** handler resolve |
| `FUN_005092b0` … `FUN_00509940` | loot / type-from-prefix family |
| `FUN_00513580` Item_SumEquippedComponentValues | related table family consumer |

---

## 6. Gaps / open

1. Product/PDB names for registry and entry.
2. Who constructs `+0x54` and writes `DAT_00d02988`.
3. Runtime / bit-exact / differential not run.

**Verdict:** **accept** — leaf CF, ABI, offsets, and family role sealed High.
