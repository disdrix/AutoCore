# Review A (reconstruction fidelity): `aa_004d32c0` CVOGSectorMap_OnCharacterEnter_IncLevelIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d32c0` |
| **VA** | `0x004d32c0`–`0x004d330d` |
| **Canonical name** | `CVOGSectorMap_OnCharacterEnter_IncLevelIndex_Inferred` (Ghidra `FUN_004d32c0`) |
| **Ghidra name** | `FUN_004d32c0` |
| **Prior alias** | `Named_CalleeOf_Client_RecvCreateCharacter_004d32c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-E) |
| **Counterpart** | `reviews/B_aa_004d32c0_CVOGSectorMap_OnCharacterEnter_IncLevelIndex_Inferred.md` |
| **System** | sector-map / combat-pool level index |
| **Live tools** | `decompile_function`, `read_memory`, `get_function_callers`, `get_xrefs_to` |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Sector-map character-enter bookkeeping** on `CVOGSectorMap` (`this`):

```c
// __thiscall; ret 8
int* CVOGSectorMap_OnCharacterEnter_IncLevelIndex_Inferred(
    SectorMap *this, Object *entering, char notifyPools);
```

1. `this+0xe818` (**level / power index**, same field combat-pool paths use as table index) **+= 1**.
2. If `notifyPools != 0`: call sibling `FUN_004d28c0(this, oldIndex, newIndex)` with `old = post-1`, `new = post` → optional combat-pool rescale fan-out.
3. Read entering object's race byte from dual-base walk:
   `entering → +4 → +4 → +0xac+entering → +0x3c → +0x532` (byte; 0/1/2 = H/M/B).
4. `this+0xe81c[race] += 1` (per-race headcount histogram).
5. Return pointer to the incremented race-counter cell.

**Sibling** `FUN_004d3310` is the **decrement** twin (leave path): `+0xe818--`, race bucket `--`, same optional `004d28c0` notify with swapped old/new (already dual-sealed).

**Production caller:** `Client_RecvCreateCharacter` @ `0x008147ae` (static xref).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `decompile_function` @ `0x004d32c0` ≡ raw |
| Live body bytes | `read_memory` 96 B @ `0x004d32c0` — ends `c2 08 00` |
| Twin dual | `A/B_aa_004d3310_CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred` |
| Notify callee dual | `A/B_aa_004d28c0_CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred` |
| Callers | `get_xrefs_to` → `Client_RecvCreateCharacter` @ `008147ae` |
| Raw / annotated / clean | `raw/aa_004d32c0_*`, `reconstructed-exact/FUN_004d32c0.cpp` |
| Function record | `functions/aa_004d32c0_FUN_004d32c0.md` |

**Not performed:** Launcher, runtime golden, bit-exact image diff, parent ledger edits.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF dual A≡B ≡ raw ≡ live | **Confirmed** | decompile identity + bytes |
| `__thiscall` + 2 stack args + **`ret 8`** | **Confirmed** | `mov esi,ecx`; epilogue `c20800` |
| Increments `+0xe818` then optional `004d28c0` | **Confirmed** | `add [esi+0xe818],1`; gated call |
| Notify args = (new−1, new) | **Confirmed** | `push eax; add eax,-1; push eax` order → stdcall stack (old,new) with ECX=this |
| Race histogram at `+0xe81c[race]` | **Confirmed** | `add [esi+edx*4+0xe81c],1` |
| Dual-base race walk +0x532 | **Confirmed** | same bytes pattern as leave twin |
| Sibling `004d3310` is −1 twin | **Confirmed** | sealed dual + live decomp |
| Caller = RecvCreateCharacter | **Confirmed** | xrefs |
| Product name / exact English of `+0xe818` | **Open** | keep `_Inferred` |
| Whether `+0xe818` is true “level” vs power band | **Probable** | pool table index 0..0xF via `004d28c0` |
| Bit-for-bit / runtime harness | **Open** | deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| `this+0xe818 += 1` | **Yes** |
| if `notifyPools`: call `004d28c0(old,new)` | **Yes** |
| race = def walk `+0x532` | **Yes** |
| `this+0xe81c[race] += 1` | **Yes** |
| return `&this+0xe81c[race]` | **Yes** |
| `ret 8` | **Yes** |

### Recovered CF (byte-aligned)

```c
// __thiscall (this, entering, notifyPools); ret 8
int *CVOGSectorMap_OnCharacterEnter_IncLevelIndex_Inferred(
    void *this, void *entering, char notifyPools)
{
    *(int *)((char *)this + 0xe818) += 1;
    if (notifyPools != 0) {
        int neu = *(int *)((char *)this + 0xe818);
        FUN_004d28c0(this, neu - 1, neu);
    }
    unsigned race = /* dual-base walk to def+0x532 */;
    int *cell = (int *)((char *)this + 0xe81c + race * 4);
    *cell += 1;
    return cell;
}
```

---

## 5. Assembly contract (from `read_memory`)

```
004d32c0  56                 push esi
004d32c1  8bf1               mov  esi, ecx
004d32c3  838618e8000001     add  dword [esi+0xe818], 1
004d32ca  807c240c00         cmp  byte [esp+0xc], 0
004d32cf  8b8618e80000       mov  eax, [esi+0xe818]
004d32d5  740a               jz   skip
004d32d7  50                 push eax            ; new
004d32d8  83c0ff             add  eax, -1
004d32db  50                 push eax            ; old
004d32dc  e8dff5ffff         call FUN_004d28c0
skip:
004d32e1  8b442408           mov  eax, [esp+8]   ; entering
004d32e5  8b4804             mov  ecx, [eax+4]
004d32e8  8b5104             mov  edx, [ecx+4]
004d32eb  8b8402ac000000     mov  eax, [edx+eax+0xac]
004d32f2  8b483c             mov  ecx, [eax+0x3c]
004d32f5  0fb69132050000     movzx edx, byte [ecx+0x532]
004d32fc  8384961ce8000001   add  dword [esi+edx*4+0xe81c], 1
004d3303  8d84961ce80000     lea  eax, [esi+edx*4+0xe81c]
004d330a  5e                 pop  esi
004d330b  c20800             ret  8
```

Hex (body through `ret 8`):  
`568bf1838618e8000001807c240c008b8618e80000740a5083c0ff50e8dff5ffff8b4424088b48048b51048b8402ac0000008b483c0fb691320500008384961ce80000018d84961ce800005ec20800`

---

## 6. Layout (this body)

| Off | Field | Role |
|---|---|---|
| `+0xe818` | levelIndex / power index (dword) | incremented; combat-pool table index source elsewhere |
| `+0xe81c` | raceHist[…] (dword array) | index by def `+0x532` |

---

## 7. Callers / callees (OWN context)

| Dir | VA | Role |
|---|---|---|
| Caller | `0x008147ae` `Client_RecvCreateCharacter` | create-character enter |
| Callee | `0x004d28c0` | optional level-index → pool rescale |
| Twin | `0x004d3310` | leave −1 path (sealed) |

---

## 8. Gaps

1. Retail / PDB symbol.
2. Exact English of `+0xe818` (level vs power-band index).
3. `notifyPools` semantics at RecvCreateCharacter call site (always vs local-player gate).
4. Full raceHist array length.
5. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps** — sealed enter-path CF, ABI, layout offsets, twin relationship, and optional pool notify; product naming open.
