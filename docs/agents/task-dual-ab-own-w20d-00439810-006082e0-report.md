# Dual A/B report — W20-D OWN (`aa_00439810`, `aa_006082e0`)

**Date:** 2026-07-29  
**Agent:** W20-D OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00439810`, `0x006082e0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ xrefs / callees / assembly_context). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` (image base `0x400000`).  
**Dual A/B:** fidelity (A) vs adversarial (B) reviews — not two programs.

---

## Verdicts

| Unit | Canonical name | Verdict |
|------|----------------|---------|
| `aa_00439810` / `0x00439810` | `stoChunkWriter_WriteU32` | **accept** |
| `aa_006082e0` / `0x006082e0` | `Outpost_CaptureOutpost` | **accept-with-gaps** |

---

## Sealed facts — `0x00439810` stoChunkWriter_WriteU32

1. **ABI:** Register-shaped — **ESI = writer**, **EAX = `const uint32_t*`**, epilogue **`pop ecx; ret`**. Not ECX thiscall. Body **`0x00439810`–`0x00439861`**.

2. **Mode gate:** `writer+0x1c == 0` → binary raw **4-byte** write via stream vtbl `+0x18`; else text path.

3. **Text path:** `stoChunkWriter_WriteFormatted("%u", v)` with format DAT **`0x00a9d718`** = `"%u"`; clear `writer+0x20`; write **`"\r\n"`** @ `0x00a97b84` size 2.

4. **Return:** `writer.status` OR-accumulated at **`+0x04`**.

5. **Twin:** Identical CF to dual-sealed `stoChunkWriter_WriteI32` (`0x00439870`) which uses `"%i"`.

6. **Name:** `stoChunkWriter_WriteU32` — family role + unsigned format. Former `FUN_00439810` / effEffect callee alias.

7. **Three-rep:** raw ≡ live decompile ≡ body bytes / format DATs.

### Gaps (`00439810`)

1. Stream interface product type / vtbl method name.  
2. Runtime golden dumps.  
3. Product C++ class English beyond family duals.

---

## Sealed facts — `0x006082e0` Outpost_CaptureOutpost

1. **ABI:** MSVC **`__thiscall`** — **ECX = outpost**, stack **capturerCtx** (nullable), epilogue **`ret 4`**. Body **`0x006082e0`–`0x00608614`**.

2. **Product string:** `"Invalid faction in CaptureOutpost = %d"` @ **`0x009dec4c`**.

3. **Capturer resolve:** if ctx non-null → vtbl **`+0x210`(0)** → root object; **`Object_GetRootRaceId`** → `newFaction`. Seed before resolve: **3**.

4. **Gates:**  
   - `newFaction != *(this+0x234)`  
   - `*(this+0x248) != 0` (timer blob)  
   - `newFaction` in **[0, 3]** else log + return  
   - world flag **`+0x7e`** required for transfer block

5. **Nearby credit:** same root race as `newFaction`, distSq < `(this+0x218)²`, via world object vector `@ +0xe75c/+0xe760`; helper `FUN_00418d70`.

6. **Success chain (thiscall ECX=this):**  
   `00606820(old)` → `00606890(old)` → `00606ff0(old)` →  
   `00606900(new)` → `00606a00(new)` → **`Outpost_CastSkillsForFaction(new)`** →  
   `00606a70(new, capturerBase)` → store **`+0x234=new`** → **`Outpost_UpdateBeaconShareRatio`** →  
   schedule count from DAT vectors (bank via `+0x220`) → timer float/`GetTickCount` → `006081b0(capturer)`.

7. **Callers:** `0x0057c88d` (push capturer; this=EAX); `0x00650752` (push 0; this=EDI).

8. **Name:** `Outpost_CaptureOutpost` — product string. Former `FUN_006082e0`.

9. **Three-rep:** raw 2026-07-23 CF ≡ live decompile ≡ prologue/epilogue/string/call-target seal.

### Gaps (`006082e0`)

1. Product English for unresolved bank helpers (`00606820`…`00606a70`, `006081b0`, `004cd5*`).  
2. capturerCtx concrete type + vtbl `+0x210`.  
3. `FUN_00418d70` credit semantics.  
4. Schedule DAT bank product meaning (`+0x220`).  
5. Runtime / bit-exact / differential — open.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x00439810` | `reviews/A_aa_00439810_stoChunkWriter_WriteU32.md` | `reviews/B_aa_00439810_stoChunkWriter_WriteU32.md` | **accept** |
| `0x006082e0` | `reviews/A_aa_006082e0_Outpost_CaptureOutpost.md` | `reviews/B_aa_006082e0_Outpost_CaptureOutpost.md` | **accept-with-gaps** |

---

## Files

### `aa_00439810` / `stoChunkWriter_WriteU32`

| Kind | Absolute path |
|------|----------------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_00439810_stoChunkWriter_WriteU32.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_00439810_stoChunkWriter_WriteU32.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00439810_stoChunkWriter_WriteU32.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00439810_FUN_00439810.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\stoChunkWriter_WriteU32.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_00439810.cpp` |
| Raw (+ re-verify append) | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00439810_FUN_00439810.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00439810_FUN_00439810.annotated.md` |

### `aa_006082e0` / `Outpost_CaptureOutpost`

| Kind | Absolute path |
|------|----------------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_006082e0_Outpost_CaptureOutpost.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_006082e0_Outpost_CaptureOutpost.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_006082e0_Outpost_CaptureOutpost.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_006082e0_FUN_006082e0.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\Outpost_CaptureOutpost.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_006082e0.cpp` |
| Raw (+ re-verify append) | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_006082e0_FUN_006082e0.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_006082e0_FUN_006082e0.annotated.md` |

### This report

`C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-own-w20d-00439810-006082e0-report.md`

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x00439870` | `stoChunkWriter_WriteI32` (signed twin; dual W19-Q) |
| `0x00767160` | `stoChunkWriter_WriteFormatted` |
| `0x00606d70` | `Outpost_CastSkillsForFaction` (called on success) |
| `0x006078e0` | `Outpost_UpdateBeaconShareRatio` (after faction store) |
| `0x006070e0` | `Outpost_CastSkillsForBeaconShare` (ratio consumer) |
| `0x00512440` | `Object_GetRootRaceId` |
| `0x00606820`…`0x00606a70` | Unresolved old/new bank helpers |
| `0x006081b0` | Post-capture notify helper |
| `0x004cd5f0` / `0x004cd5d0` | Pre-capture faction side effects |

---

## AutoCore impact

- **stoChunk serializers:** use **WriteU32** for unsigned scalars (`"%u"` text / 4-byte binary); do not swap with WriteI32; status is OR-accumulated, not the value.  
- **Outpost capture:** require faction change + timer blob + world `+0x7e`; cast faction skills then store faction then recompute beacon-share ratio; arm schedule/timer after store; nearby credit uses capturer race and squared radius at `+0x218`.
