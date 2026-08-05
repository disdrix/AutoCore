# Dual A/B report — W20-E OWN-ONLY (`0x00449dc0`, `0x0096de80`)

**Date:** 2026-07-29  
**Agent:** W20-E OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00449dc0`, `0x0096de80`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis / assembly context). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00449dc0` phyBoneSharedData_CreateDefaultAndInstall | **accept** — **EBX slot install, 0x90 identity shared, AddRef/Release sealed; product spelling residual** |
| `aa_0096de80` phyBone_CopySharedQsTransformToLocal | **accept** — **EAX bone, 10-float qs copy + +0x140=-1 sealed; leaf** |

---

## `aa_00449dc0` — phyBoneSharedData_CreateDefaultAndInstall

### Sealed facts

1. **Body:** `0x00449dc0`–`0x00449e72` exclusive (**178** B). Final `c3` at `0x00449e71`; following `cc` pad then `FUN_00449e80`.

2. **ABI:** **EBX = container***; install at **`*(EBX+4)`**; bare **`ret`**. Saves ESI. **Not** ECX-thiscall. No stack args.

3. **Call-site mapping:** all 5 sites `LEA EBX,[bone+0xf0]` before CALL → slot = **`bone+0xf4`** (phyBoneSharedData*).

4. **Algorithm:** `operator_new(0x90)` → default construct (vtbl `PTR_FUN_00aa050c`, identity hkQsTransform quat/trans/scale, identity bind 4x4 from `DAT_00afdf70`, `+0x80=0`) → AddRef (`vtbl+4` empty on first) → Release old (`vtbl+8`) → store.

5. **Globals:** `g_flOne` @ `0x00a0f2a0` = `1.0f`; identity matrix `DAT_00afdf70`; `DAT_00d1eac0` → field `+0x08`.

6. **Callees:** `operator_new`; virtuals only (empty first-ref; release helper `@0x00464890`).

7. **Callers (5):** `FUN_0096e1f0` @ `0096e242`; `phyBone_unserialize` @ `0096e3b1`; `FUN_0095dc70` ×3.

8. **Name:** structural `phyBoneSharedData_CreateDefaultAndInstall`. Residual auto-seed `Named_CalleeOf_Named_gfxBodyMassageMachine_00449dc0` **misleading**. Co-located string `"Collision shape already set!"` is **not** body-used (shape lives at `+0x80` later).

### Gaps

1. Product/PDB method spelling.  
2. Full English of `+0x08` / `DAT_00d1eac0`.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00449dc0_phyBoneSharedData_CreateDefaultAndInstall.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00449dc0_phyBoneSharedData_CreateDefaultAndInstall.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00449dc0_phyBoneSharedData_CreateDefaultAndInstall.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00449dc0_phyBoneSharedData_CreateDefaultAndInstall.md` |
| Function record | `docs/reconstruction/functions/aa_00449dc0_phyBoneSharedData_CreateDefaultAndInstall.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00449dc0_FUN_00449dc0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/phyBoneSharedData_CreateDefaultAndInstall.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00449dc0.cpp` |
| Raw | `docs/reconstruction/raw/aa_00449dc0_FUN_00449dc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00449dc0_FUN_00449dc0.annotated.md` |

---

## `aa_0096de80` — phyBone_CopySharedQsTransformToLocal

### Sealed facts

1. **Body:** `0x0096de80`–`0x0096dedd` exclusive (**93** B). Final `c3`; following `cc` pad.

2. **ABI:** **EAX = phyBone***; bare **`ret`**. Saves ESI/EDI. **Leaf** (no callees).

3. **CF:** `shared=*(EAX+0xf4)`; copy **10** dwords shared`+0x0c..+0x30` → bone`+0x04..+0x28`; `*(EAX+0x140)=0xffffffff`.

4. **Copy map:** quat4 (`+0xc`→`+4`), trans3 (`+0x1c`→`+0x14`), scale3 (`+0x28`→`+0x20`). **Not** bind 4x4 / collision.

5. **Callees:** none.

6. **Callers (2):** `phyBone_unserialize` @ `0096e3cc` (`MOV EAX,ESI`); `FUN_0095dc70` @ `0095e232` (`MOV EAX,EBP`).

7. **Name:** structural `phyBone_CopySharedQsTransformToLocal`. Residual gfxMassage auto-seed **misleading**.

### Gaps

1. Product/PDB method spelling.  
2. English of `+0x140` sentinel consumers.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0096de80_phyBone_CopySharedQsTransformToLocal.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0096de80_phyBone_CopySharedQsTransformToLocal.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0096de80_phyBone_CopySharedQsTransformToLocal.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0096de80_phyBone_CopySharedQsTransformToLocal.md` |
| Function record | `docs/reconstruction/functions/aa_0096de80_phyBone_CopySharedQsTransformToLocal.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_0096de80_FUN_0096de80.md` |
| Clean | `docs/reconstruction/reconstructed-exact/phyBone_CopySharedQsTransformToLocal.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0096de80.cpp` |
| Raw | `docs/reconstruction/raw/aa_0096de80_FUN_0096de80.md` |
| Annotated | `docs/reconstruction/raw/aa_0096de80_FUN_0096de80.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### CreateDefaultAndInstall (`0x00449dc0`)

- Port as **RefCounted replace** of default shared-data object at **`bone+0xf4`** (via container at `bone+0xf0`), not a free-standing shape factory.
- Preserve **identity qs + identity bind matrix + null shape** defaults before BDAT fill.
- Honor AddRef/Release; allow null install if `new` fails.
- Do **not** substitute ECX-thiscall bone member or write the 0x90 blob into bone local qs (`+4`).

### CopySharedQsTransformToLocal (`0x0096de80`)

- After shared unserialize, **copy 10 floats only** into bone locals; set **`+0x140 = -1`**.
- Do not deep-copy bind matrix or collision slot here.
- Call with bone in **EAX** (or explicit equivalent); shared at `+0xf4` must already be installed.

### Pairing

Retail PBON path: **install default shared** → **BDAT unserialize** → **copy qs to bone locals**. Both owned VAs are the bookends of that sandwich (BDAT is already sealed separately).

---

## This report

`docs/agents/task-dual-ab-00449dc0-0096de80-w20e-report.md`
