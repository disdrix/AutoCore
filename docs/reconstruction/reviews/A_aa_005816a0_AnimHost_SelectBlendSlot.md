# Review A (reconstruction fidelity): `aa_005816a0` AnimHost_SelectBlendSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_005816a0` |
| **VA** | `0x005816a0` |
| **Canonical name** | `AnimHost_SelectBlendSlot` (inferred; Ghidra `FUN_005816a0`) |
| **Plate alias** | `Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_005816a0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005816a0_AnimHost_SelectBlendSlot.md` |
| **System** | client anim / special-event |
| **Evidence pass** | Live decompile + `read_memory` full body; callers Respawn/Teleport special events |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Select one animation channel / blend slot** on an anim host (`this`):

1. For **19** slots (`0x13`) starting at `this+0x2c` (pointer array):
   - If slot non-null → call host mixer vfunc `*(this+0x24)->vtbl+0x18(slot, blendArg, 0.0f)` — **zero weight** / clear.
2. If selected slot `this+0x2c + mode*4` non-null:
   - Sample time via `FUN_0079a110` → `FUN_0074e910(0, t)`.
   - Call same vfunc with weight **`1.0f`** (`0x3f800000`) and caller **blend** arg.
   - If vfunc returns **0** → return **1** (busy/fail-ish); else fall through.
3. Return **0** (ok / idle).

Callers (Respawn Update, TeleportIn/Out, setup helper) pass **mode ∈ {0,1,2,3}** and blend **0.0f or 0.1f** (`0x3dcccccd`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005816a0_FUN_005816a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005816a0_FUN_005816a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005816a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005816a0_FUN_005816a0.md` |
| Callers | Respawn Update/setup, TeleportIn/Out ctors, siblings |
| Live | `read_memory` body; **`ret 8`** |

**Three-rep:** present.

---

## 3. Signature (image-sealed)

```c
// __thiscall  ECX = anim host*
// stack: int mode, float blendWeight   (ret 8)
// returns 1 if select vfunc returned 0; else 0
int AnimHost_SelectBlendSlot(void *host, int mode, float blendWeight);
```

| Item | Evidence | Conf |
|---|---|---|
| `ret 8` | body epilogue | **High** |
| Slot table base `+0x2c` | lea edi,[esi+0x2c]; index*4 | **High** |
| Mixer object `+0x24` | mov ecx,[esi+0x24] | **High** |
| Vfunc `+0x18` | `call [edx+0x18]` | **High** |
| Clear weight **0** then select weight **1.0f** | push 0 / push 0x3f800000 | **High** |
| Loop count **19** | `mov ebp, 0x13` | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Clear all 19 non-null slots at weight 0 | **Yes** | **High** |
| Skip select if target slot null → return 0 | **Yes** | **High** |
| Time sample + `FUN_0074e910` before select | **Yes** | **High** |
| Select with weight 1.0 + caller blend | **Yes** | **High** |
| Invert vfunc bool → return 1 | **Yes** | **High** |
| No string work / no CBID | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = exclusive blend-slot select | **High** | clear-all then enable one |
| 19-slot table at `+0x2c` | **High** | loop immediate |
| Modes 0–3 used by special events | **High** | call-site immediates in parent duals |
| Return 1 = select failed/busy | **Probable** | inverted char from vfunc |
| Product mixer class name | **Open** | residual |
| Exact meaning of blend arg vs weight 1.0 | **Tentative** | both passed; English open |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Product name of host / vfunc `+0x18`.
2. Full slot enum (only 0–3 observed at call sites; table has 19).
3. Semantics of return code for Update phase machines.
4. Own dual for `FUN_0079a110` / `FUN_0074e910` time path.

**Verdict:** **accept-with-gaps**
