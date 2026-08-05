# Review A (reconstruction fidelity): `aa_00404730` CombatFloater_CopyRange_0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404730` |
| **VA** | `0x00404730` |
| **Canonical name** | `CombatFloater_CopyRange_0x38_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_00404730` |
| **Prior alias** | `Named_CalleeOf_…_Cli_00404730` (parent-seed chain) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-E) |
| **Counterpart** | `reviews/B_aa_00404730_CombatFloater_CopyRange_0x38_Inferred.md` |
| **System** | missions-progression / combat floater UI |
| **Live tools** | `decompile_function`, `read_memory`, `get_function_callers` |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Range POD copy / relocate worker** for combat-floater elements (**stride `0x38`**):

```c
// cdecl — returns advanced destination cursor
void *CombatFloater_CopyRange_0x38_Inferred(
    void *srcBegin, void *srcEnd, void *dst);
```

1. Install SEH frame (`LAB_009bd1d0`).
2. For each element in half-open range `[srcBegin, srcEnd)` stepping **`+0x38`**:
   - `FUN_004046f0(dst, src)` — pod copy **14 dwords** (= **0x38** bytes) if `dst != NULL`.
   - `dst += 0x38`.
3. Tear down SEH; **return advanced `dst`**.

**Sole static caller:** `FUN_004044c0` / `CombatFloater_UninitializedCopy_0x38_Inferred` (thin trampoline used by `CombatFloaterVector_InsertN` realloc/relocate).

**Not** construct-from-template fill (`00404600` / `004044e0` / `00402ea0`); **not** the single-element leaf (`004046f0`); **not** vector growth itself (`00403680`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `decompile_function` @ `0x00404730` ≡ raw |
| Live body bytes | `read_memory` 100 B @ `0x00404730` — epilogue `…8be55dc3` (**cdecl `ret`**) |
| Element leaf dual | `A/B_aa_004046f0_CombatFloater_PodCopyElement_0x38_Inferred` |
| Trampoline dual | `A/B_aa_004044c0_CombatFloater_UninitializedCopy_0x38_Inferred` |
| Leaf bytes | `read_memory` @ `0x004046f0` — `ecx=0xe`, `rep movsd`, `ret 8` |
| Callers | `get_function_callers` → only `FUN_004044c0` |
| Parent insert dual | `A_aa_00403680_CombatFloaterVector_InsertN_0x38_Inferred` |
| Raw / annotated / clean | `raw/aa_00404730_*`, `reconstructed-exact/FUN_00404730.cpp` |

**Not performed:** Launcher, runtime golden, bit-exact, parent ledger edits.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF dual A≡B ≡ raw ≡ live | **Confirmed** | decompile identity |
| Loop stride **`0x38`** | **Confirmed** | `add edi/esi, 0x38` |
| Element copy via **`FUN_004046f0`** | **Confirmed** | call target + leaf dual |
| Element size **14 dwords** | **Confirmed** | leaf `mov ecx, 0xe` / `f3 a5` |
| Returns advanced **dst** | **Confirmed** | `mov eax, edi` before teardown |
| **cdecl** (`ret` / `c3`) | **Confirmed** | epilogue bytes |
| SEH frame present | **Confirmed** | `push LAB_009bd1d0` / ExceptionList |
| Sole caller `004044c0` | **Confirmed** | xrefs |
| Floater relocate role | **High** | parent dual + insert path |
| Decompiler 3 formals are the used ones | **High** | `[ebp+8/+c/+10]`; `[ebp+14]` dead for leaf |
| Product / PDB name | **Open** | `_Inferred` |
| Bit-for-bit / runtime | **Open** | deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| SEH install | **Yes** |
| while `src != srcEnd` | **Yes** |
| `PodCopy0x38(dst, src)` | **Yes** |
| `dst += 0x38; src += 0x38` | **Yes** |
| return `dst` | **Yes** |
| No alloc / no vtable stamp | **Yes** |

### Recovered CF (byte-aligned)

```c
// cdecl
void *CombatFloater_CopyRange_0x38_Inferred(
    unsigned char *srcBegin, unsigned char *srcEnd, unsigned char *dst)
{
    // SEH (LAB_009bd1d0) present in retail
    for (; srcBegin != srcEnd; srcBegin += 0x38) {
        FUN_004046f0(dst, srcBegin); // 0x38 POD if dst != NULL
        dst += 0x38;
    }
    return dst;
}
```

---

## 5. Assembly contract (from `read_memory`)

Prologue: standard MSVC SEH (`push ebp; mov ebp,esp; push -1; push LAB_009bd1d0; fs:[0]…`).

Loop core:

```
; ebx = [ebp+0x14]   ; loaded but unused by pod leaf
; edi = [ebp+0x10]   ; dst
; esi = [ebp+8]      ; srcBegin
loop:
  cmp  esi, [ebp+0xc]
  jz   done
  push esi                 ; src
  push edi                 ; dst
  mov  ecx, ebx            ; dead
  call FUN_004046f0        ; stdcall ret 8
  add  edi, 0x38
  mov  [ebp+0x10], edi
  add  esi, 0x38
  mov  [ebp+8], esi
  jmp  loop
done:
  mov  eax, edi            ; return dst
  ; SEH teardown; pop edi/esi/ebx; leave; ret (c3)
```

Hex (full function through `ret`):  
`558bec6aff68d0d19b0064a1000000005064892500000000515356578965f0c745fc000000008b5d148b7d108b7508903b750c741756578bcbe882ffffff83c738897d1083c638897508ebe4c745fcffffffff8bc78b4df464890d000000005f5e5b8be55dc3`

---

## 6. Family map (OWN context)

| VA | Role |
|---|---|
| `0x004046f0` | Pod copy **one** 0x38 element |
| **`0x00404730`** | **This** — copy range, return new dst end |
| `0x004044c0` | Trampoline → this (`ret 0x0C`) |
| `0x00403680` | vector InsertN (calls trampoline on realloc) |
| `0x00404600` | ConstructN from single template (different) |

---

## 7. Gaps

1. Retail / PDB symbol.
2. Why trampoline pushes 5 stack dwords (MSVC artifact; 4th formal unused by leaf CF).
3. Whether any non-floater client reuses this worker (static sole caller).
4. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps** — sealed range-copy CF, stride, leaf callee, cdecl return-dst, and floater-relocate role via sole caller.
