# Review B (skeptical / adversarial): `aa_004bae00` Host_DualCNDHash_TraverseNextObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bae00` |
| **VA** | `0x004bae00` |
| **Canonical name** | `Host_DualCNDHash_TraverseNextObject_Inferred` |
| **Review date** | `2026-08-05` (MEGA-011 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004bae00_Host_DualCNDHash_TraverseNextObject_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context` + `read_memory` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Identity is LoadMapFile leaf (`Named_CalleeOf_*`) | **Falsified** — 28 call sites are pick/flush/world sweeps; no map-load chain in body |
| 2 | Is `List_TraversalLock` / CS list step | **Falsified** — flag `hash+0x1d` only; no EnterCS; CS family uses `+0x28` |
| 3 | Holds lock across multi-step walk | **Falsified** — every success path clears `+0x1d` before RET |
| 4 | flag 0 uses list A (`+0x4`) | **Falsified** — asm: flag0 → `+0xd`/`+0x8`; flag≠0 → `+0xc`/`+0x4` |
| 5 | cdecl / bare RET / no stack cleanup | **Falsified** — three **`RET 8`** (`C2 08 00`) |
| 6 | ECX = Client* / stack = host | **Falsified** — entry `MOV ESI,ECX`; body reads host+4/8/c/d; SelectBestPick loads `ECX=[Client+0xBC]` |
| 7 | Returns hash node* not object* | **Falsified** — `004bc530` returns `*(node+0xc)`; callers treat EAX as object (vtbl calls) |
| 8 | Decompiler void / wrong arity | **Falsified** — analyze locals: ECX host + stack char + stack ptr; RET 8 |
| 9 | Same as `CNDHash_TraverseToNext` alone | **Falsified** — host dual-select + lock sandwich wrapper; walk is callee |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Decisive machine dataflow

```text
CMP  [ESP+4], 0              // listSelect
MOV  ESI, ECX                // host
JZ   flag0

// flag != 0
CMP  [ESI+0xC], 0            // enable A
MOV  ECX, [ESI+0x4]          // hash A
CALL 00402c40                // lock
PUSH [ESP+0xC]               // cursor
MOV  ECX, [ESI+0x4]
CALL 004bc530                // next → EAX payload
MOV  ECX, [ESI+0x4]
MOV  byte [ECX+0x1D], 0      // unlock
RET  8

flag0:
CMP  [ESI+0xD], 0            // enable B
MOV  ECX, [ESI+0x8]          // hash B
// same lock / walk / unlock
RET  8

fail:
XOR  EAX, EAX
RET  8
```

SelectBestPick call-site (`0x0049010b`):

```text
MOV  ECX, [EDI+0xBC]         // host (Client field)
PUSH cursor*
PUSH listSelect              // 0, later toggled to 1
CALL 0x004bae00
MOV  ESI, EAX                 // object*
```

A ≡ B on live decompile + body hex + xrefs + assembly context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual-list CF + flag polarity | **High** | wrong list enumerated |
| thiscall + RET 8; ECX=host | **High** | stack smash / wrong this |
| Lock sandwich + inline unlock | **High** | double-lock / stuck flag |
| Return = object payload | **High** | type confusion at callers |
| SelectBestPick host binding | **High** | parent gap stays open |
| Product host English | Medium | naming only |
| Runtime | **Open** | not claimed |

---

## 4. Surviving contract for AutoCore

```csharp
// Single-step dual-CNDHash host enumerator
object? TraverseNextObject(DualHashHost host, byte listSelect, ref nint cursor)
{
    int hashPtr;
    if (listSelect == 0)
    {
        if (host.EnableB == 0 || host.ListB == 0) return null;
        hashPtr = host.ListB; // host+0x8
    }
    else
    {
        if (host.EnableA == 0 || host.ListA == 0) return null;
        hashPtr = host.ListA; // host+0x4
    }

    CNDHash_TraversalLock_Set(hashPtr);          // +0x1d = 1 (soft)
    var obj = CNDHash_TraverseToNext_Payload0C(hashPtr, ref cursor);
    Marshal.WriteByte(hashPtr + 0x1d, 0);        // unlock
    return obj;
}
// ABI: thiscall host in ECX; RET 8. Distinct from CS List_Traversal* family.
// Port SelectBestPick with two passes listSelect 0 then 1 over Client+0xBC.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller roles and retires LoadMapFile scaffold. Residual product host English + `004bc530` dual → **accept-with-gaps**.
