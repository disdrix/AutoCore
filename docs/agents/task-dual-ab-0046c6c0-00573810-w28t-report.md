# Dual A/B report — W28-T OWN-ONLY (`0x0046c6c0`, `0x00573810`)

**Date:** 2026-07-29  
**Agent:** W28-T OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0046c6c0`, `0x00573810`. Dual A/B + artifacts.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave28_partition_map.md` → W28-T  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / callers / callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0046c6c0` StdTree_Buynode_Val12_EsiValue | **accept** — Val12 node buy; ESI value; `ret 0x10`; isnil@+0x19=0; distinct from stack twin `005ae220` |
| `aa_00573810` StdMap_InsertOrFind_Val12_UintKey | **accept-with-gaps** — Val12 insert-or-find by uint key; out-pair; equal-no-write; `ret 8`; insert via `00573510` |

---

## `aa_0046c6c0` — StdTree_Buynode_Val12_EsiValue

### Sealed facts

1. **Body:** `0x0046c6c0`–`0x0046c702` exclusive (**66** B / `0x42`). Final **`c2 10 00`** (`ret 0x10`); following `cc` pad.

2. **ABI:** `__stdcall`; four stack args `(left, parent, right, color)`; value pointer in **ESI**; return **EAX** = node* \| null; clean **16** B.

3. **Algorithm:**
   ```
   n = operator_new(0x1c)
   if n:
     n.left/parent/right = args
     copy ESI[0..2] → n+0x0c
     n.color = arg4; n.isnil = 0
   return n
   ```

4. **Callees:** `operator_new` only.

5. **Callers (2):** `FUN_0043c2e0` @ `0x0043c348`; `FUN_0044a8c0` @ `0x0044a928` (Map_TreeInsertAndRebalance_Val12_EsiBuy, W27-P).

6. **Peer twin:** `StdTree_Buynode_Val12` @ `0x005ae220` — same layout; **stack** `value*` + **`ret 0x14`**. **Do not merge.**

7. **Name:** structural `StdTree_Buynode_Val12_EsiValue`. Legacy effDeviceEff seed is **narrow**.

### Gaps

1. Product/MSVC demangle per map instantiation.  
2. Runtime OOM path.  
3. Bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0046c6c0_StdTree_Buynode_Val12_EsiValue.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0046c6c0_StdTree_Buynode_Val12_EsiValue.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0046c6c0_StdTree_Buynode_Val12_EsiValue.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0046c6c0_StdTree_Buynode_Val12_EsiValue.md` |
| Function record | `docs/reconstruction/functions/aa_0046c6c0_StdTree_Buynode_Val12_EsiValue.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_0046c6c0_FUN_0046c6c0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val12_EsiValue.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0046c6c0.cpp` |
| Raw | `docs/reconstruction/raw/aa_0046c6c0_FUN_0046c6c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0046c6c0_FUN_0046c6c0.annotated.md` |

---

## `aa_00573810` — StdMap_InsertOrFind_Val12_UintKey

### Sealed facts

1. **Body:** `0x00573810`–`0x005738c8` exclusive (**184** B / `0xB8`). Three exits **`c2 08 00`** (`ret 8`); pad `CC`.

2. **ABI:** `__thiscall` ECX=map; stack `(outPair*, value*)`; clean **8** B.

3. **Algorithm:**
   ```
   walk tree by uint key (value[0] vs node+0x0c); isnil@+0x19
   if goLeft && parent==leftmost: InsertAndRebalance(...,1) → out{it,1}
   else if goLeft: Predecessor(parent)
   if parent.key < key: InsertAndRebalance(...,addLeft) → out{it,1}
   else: out{parent,0}  // equal — no value rewrite
   ```

4. **Callees:** `FUN_00573510` (StdTree_InsertAndRebalance_Val12, W27-S → buy `005ae220`); `FUN_005ae050` (predecessor).

5. **Callers (3 / 4 xrefs):** `FUN_00572360` @ `0x005724d5`; `FUN_00572730` @ `0x005729b8`; `FUN_00572ab0` @ `0x00572d41`, `0x00572deb`.

6. **Node:** Val12 / 0x1c — key@+0x0c, color@+0x18, isnil@+0x19.

7. **Name:** structural `StdMap_InsertOrFind_Val12_UintKey`. Legacy ShowInventory seed is **narrow**. Peer CF: `Skill_CategoryCooldownMap_Insert` (`0x0051d2f0`) — different insert helper.

### Gaps

1. Product English / demangle for value payload (v1/v2).  
2. Full dual of inventory callers (not OWN).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00573810_StdMap_InsertOrFind_Val12_UintKey.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00573810_StdMap_InsertOrFind_Val12_UintKey.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00573810_StdMap_InsertOrFind_Val12_UintKey.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00573810_StdMap_InsertOrFind_Val12_UintKey.md` |
| Function record | `docs/reconstruction/functions/aa_00573810_StdMap_InsertOrFind_Val12_UintKey.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00573810_FUN_00573810.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_Val12_UintKey.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00573810.cpp` |
| Raw | `docs/reconstruction/raw/aa_00573810_FUN_00573810.md` |
| Annotated | `docs/reconstruction/raw/aa_00573810_FUN_00573810.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### StdTree_Buynode_Val12_EsiValue (`0x0046c6c0`)

- Port as **generic Val12 node buy with ESI value**, not device-effect-specific.
- Node size **0x1c**; color @ +0x18; isnil @ +0x19 forced 0.
- Preserve **`ret 0x10`** + ESI contract (or explicit value* port form).
- Do **not** substitute stack twin `0x005ae220` (`ret 0x14`) without matching caller ESI setup.

### StdMap_InsertOrFind_Val12_UintKey (`0x00573810`)

- Port as **insert-or-find**, not insert-or-assign — equal key leaves v1/v2 unchanged.
- Out pair `{node* @+0, inserted @+4}`; **`ret 8`**.
- Always-insert path is **`FUN_00573510`** (stack buy `005ae220`) — **not** ESI buy `0046c6c0`.
- Key compare is **unsigned** uint at value dword0 / node +0x0c.

---

## Notes

- No Launcher. No parent ledger / partition map / COVERAGE_LEDGER edits.
- Did not write dual artifacts for non-owned helpers (`00573510` dualed W27-S; `005ae220` dualed W24-I; `0044a8c0` dualed W27-P; callers inventory-side out of ownership).
- Scaffold raw bodies preserved; W28-T re-verify **appended** only.
