# Review B (skeptical / adversarial): `aa_00418d70` StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418d70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R10-025) |
| **Counterpart** | `reviews/A_aa_00418d70_StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `force_decompile` + `analyze_function_complete` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is VOG_DEBUG_STOP helper / Named_CalleeOf plate | **Falsified** — body is pure vector push; VOG string is parent failure path only |
| 2 | Domain-locked VehicleCrew-only API | **Falsified** — 13 xrefs / 8 named callers across systems |
| 3 | EAX=vec / ECX=value (Elem12 twin ABI) | **Falsified** — **ECX=vec**, stack value*; parent `LEA ECX,[ESI+0x1F4]` |
| 4 | Stride 4 or 12 or 0x28 | **Falsified** — SAR 3 + ADD 8 ⇒ **elem 8** |
| 5 | Always reallocates | **Falsified** — capacity gate fast path |
| 6 | Fast path uses ConstructN leaf | **Falsified** — raw two-dword store |
| 7 | cdecl / bare RET | **Falsified** — dual **`RET 4`** |
| 8 | MSVC vector fields at +0/+4/+8 | **Falsified for this shell** — host uses **+4/+8/+0xC** (pad/shell at +0 unread here) |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall ECX=vec + stack val* + RET 4 | **Confirmed** | Stack imbalance in ports |
| stride 8 size/cap/end advance | **Confirmed** | Wrong growth / corruption |
| fast 2×u32 POD copy | **Confirmed** | Truncated element |
| slow CALL 00418e10 | **Confirmed** | Grow path break |
| multi-domain util (not crew-only) | **Confirmed** | Over-narrow port |
| Product element English | **Inferred** | Rename churn |
| Runtime | **Open** | — |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 decompile body preserved
live force_decompile 2026-08-05 ≡ same CF
read_memory seal:
  56 8B 71 04 … C1 FA 03 … C1 F8 03 … 83 C0 08 … C2 04 00
  slow: 52 50 8D 44 24 10 50 E8 4E 00 00 00 → 00418e10 ; C2 04 00

parent 00575670:
  LEA ECX,[ESI+0x1F4]
  MOV [ESP+10],EDX / MOV [ESP+14],EAX   ; COID pair
  CALL 00418d70
```

Reject ports that:

- Keep `Named_CalleeOf_Named_VOG_DEBUG_STOP_*` as canonical.
- Treat as crew-only product API.
- Use EAX/ECX Elem12-style register ABI.
- Assume stride 4/12/0x28.
- Skip capacity gate or invent ConstructN on fast path.
- Claim runtime Confirmed without Launcher evidence.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail MSVC-style vector push_back for 8-byte POD (two u32).
// thiscall: ECX = vector host (begin@+4, end@+8, capEnd@+0xC)
// stack: const Elem8* value; RET 4
// spare capacity → raw copy; else grow via 00418e10

void StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred(
    ref VectorHost8 v,
    in Elem8 value)
{
    // see clean reconstructed-exact
}
```

Pair with undualed grow `00418e10`, parent crew insert `005755b0` (one consumer among many).

---

## 5. Verdict

**accept-with-gaps** — adversarial attacks on VOG misname, crew-only lock, wrong ABI/stride, always-realloc, ConstructN-fast, bare-RET are **falsified**. Remaining gaps: product element English, grow dual, orphans, runtime.
