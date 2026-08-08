# Review B (skeptical / adversarial): `aa_004020f0` BasicStringFlag_Dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004020f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R10-018 OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_004020f0_BasicStringFlag_Dtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Mission progression / dialog UI helper | **Falsified** — body is SEH + string dtor only; 7 callers all `Unwind@*`; no UI/strings |
| 2 | Full aggregate dtor that frees flag-related state | **Falsified** — no `+0x1c` access; flag is POD |
| 3 | Constructor or assignment | **Falsified** — sole callee is `~basic_string`; no write to object fields except free path inside CRT dtor |
| 4 | Plain cdecl / no stack cleanup | **Falsified** — epilogue **`RET 4`** (`C2 04 00`) |
| 5 | `__thiscall` with ECX = object at entry | **Falsified for wrapper ABI** — object arrives on stack; ECX loaded mid-body for nested CRT call only |
| 6 | Same as twin `FUN_00402040` (copy) | **Falsified** — copy writes string+flag, returns dest; this only destroys string, void, different IAT |
| 7 | Same as twin `FUN_00401d30` (ctor-from-parts) | **Falsified** — ctor uses IAT copy-ctor + flag store, **RET 0xC** |
| 8 | Identical to raw CRT import thunk alone | **Partial** — body is a thin SEH wrapper around the import, but has unique VA, Unwind registration, and `RET 4` contract |
| 9 | Family name `BasicStringFlag_*` is RTTI-proven | **Not proven** — membership is structural (shared SEH, twin adjacency, prior dual notes); keep `_Inferred` |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher; Terminal false) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| String dtor only + RET 4 | **Confirmed** | Stack imbalance / missed free |
| Stack object* → ECX for nested dtor | **Confirmed** | Wrong this pointer |
| Not mission dialog logic | **Confirmed** | Misleading system ownership |
| Exact product type name | **Low–Med** | Doc naming only; port still = destroy string |
| Flag product English | **Low** | Misnamed field in ports |
| Exact managed string layout | **N/A** | Use host `string` type |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean BasicStringFlag_Dtor_Inferred.cpp

64 A1 00 00 00 00    MOV EAX,FS:[0]
6A FF                PUSH -1
68 B9 BF 9B 00       PUSH LAB_009bbfb9
50                   PUSH EAX
64 89 25 00 00 00 00 MOV FS:[0],ESP
C7 44 24 08 FF FF FF FF  ; SEH state = -1
8B 4C 24 10          MOV ECX,[ESP+0x10]   ; object*
FF 15 F4 62 9C 00    CALL [0x009c62f4]    ; basic_string dtor
8B 0C 24             MOV ECX,[ESP]
64 89 0D 00 00 00 00 MOV FS:[0],ECX
83 C4 0C             ADD ESP,0xC
C2 04 00             RET 4

Callee: EXTERNAL ~basic_string
Callers: 7× Unwind@* only
Body: 0x004020f0–0x00402126 (55 B); CC pad → FUN_00402130
```

Reject ports that:

- Name this as mission-dialog / UI open helper.
- Invent flag free / delete / virtual dtor chain.
- Assume thiscall ECX-at-entry for the wrapper itself, or cdecl without `RET 4`.
- Merge identity with `00402040` (copy) or `00401d30` (ctor-from-parts).
- Drop SEH wrapper and treat as bare IAT thunk at a different VA.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aggregate (MSVC string footprint 0x1c in this binary):
//   struct BasicStringFlag { string str; byte flag; };
//
// Native call: object* on stack, callee cleans 4, nested thiscall into CRT string dtor.
// Managed port: dispose/drop the string field only; flag is POD.

sealed class BasicStringFlag
{
    public string Str;
    public byte Flag;

    // Dtor / Dispose equivalent:
    //   Str = null; // or leave to GC; no flag cleanup
}

// Family:
//   00401d30 — construct from (string*, char*)  [dualed MEGA-065]
//   00402040 — copy-ctor EDI src                [dualed MEGA-080]
//   004020f0 — this unit (string-only dtor)
// Call sites in retail are Unwind handlers, not direct mission code.
```

---

## 5. Verdict

**accept-with-gaps** — adversarial checks fail to overturn CF/ABI/string-only dtor; product type English and per-Unwind frame identity remain open → keep `_Inferred`. Mission-dialog identity **rejected**.
