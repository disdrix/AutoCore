# Review B (skeptical / adversarial): `aa_00402040` BasicStringFlag_CopyCtor_EdiSrc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402040` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-080 OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_00402040_BasicStringFlag_CopyCtor_EdiSrc_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Mission null-dialog UI helper (scaffold name) | **Falsified** — body is only string copy-ctor + 1 byte; no dialog/UI/strings; 2 structural callers |
| 2 | Plain `basic_string` copy-ctor alone | **Falsified** — extra `MOV [ESI+0x1c],AL` from `[EDI+0x1c]` after string size 0x1c |
| 3 | `__thiscall` with ECX = object | **Falsified for whole unit** — stack dest into ESI; ECX only for nested string ctor; source is **EDI** |
| 4 | cdecl / no stack cleanup | **Falsified** — epilogue **`RET 4`** (`C2 04 00`) |
| 5 | Source on stack as second formal | **Falsified** — only one stack arg (dest); source via **EDI** (`PUSH EDI` feeds string ctor only) |
| 6 | Same as twin `FUN_00401d30` | **Falsified** — `00401d30` takes string* + char* (**RET 0xC**); this copies whole aggregate from EDI (**RET 4**) |
| 7 | Assign / operator= (not ctor) | **Falsified** — SEH state 0 after string ctor path; no prior string in dest; used to init node/local slots |
| 8 | Destroys / frees | **Falsified** — no dtor/delete; dtor twin is `004020f0` (string only) |
| 9 | ESI=src / EDI=dst (RcElem28-style) | **Falsified** — ESI=dest from stack; EDI=source (opposite of RcElem28_CopyCtor_EsiEdi) |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher; Terminal false) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| String copy + flag @+0x1c | **Confirmed** | Wrong aggregate size in ports |
| EDI=src, stack=dest, RET 4 | **Confirmed** | Stack imbalance / wrong register |
| Not mission dialog logic | **Confirmed** | Misleading system ownership |
| Flag product English | **Low** | Misnamed field in ports |
| Map value_type product name | **Low** | Doc only |
| Exact managed string layout | **N/A** | Use host `string` type |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean BasicStringFlag_CopyCtor_EdiSrc_Inferred.cpp

64 A1 00 00 00 00    MOV EAX,FS:[0]
6A FF                PUSH -1
68 B9 BF 9B 00       PUSH LAB_009bbfb9
50                   PUSH EAX
64 89 25 00 00 00 00 MOV FS:[0],ESP
56                   PUSH ESI
8B 74 24 14          MOV ESI,[ESP+0x14]   ; dest
57                   PUSH EDI             ; source → string ctor stack arg
8B CE                MOV ECX,ESI
FF 15 EC 62 9C 00    CALL [0x009c62ec]    ; basic_string copy-ctor
C7 44 24 0C 00 00 00 00
8A 47 1C             MOV AL,[EDI+0x1c]
88 46 1C             MOV [ESI+0x1c],AL
...
C2 04 00             RET 4

IAT demangle: ??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAE@ABV01@@Z
Callers: 0040200a (FUN_00401fe0), 009801c0 (FUN_00980160)
```

Reject ports that:

- Name this as mission null-dialog / UI open helper.
- Drop the flag byte or treat size as plain 0x1c string only.
- Assume thiscall ECX=aggregate or cdecl without `RET 4`.
- Swap EDI/ESI vs RcElem28 register convention.
- Merge identity with `FUN_00401d30` (different arity / RET).

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aggregate (MSVC string footprint 0x1c in this binary):
//   struct BasicStringFlag { string str; byte flag; };
//
// Native call: dest on stack, source in EDI, returns dest, callee cleans 4.
// Managed port: ordinary copy of (string, byte) — no EDI convention needed.

sealed class BasicStringFlag
{
    public string Str;
    public byte Flag;

    public BasicStringFlag(BasicStringFlag other)
    {
        Str = other.Str;
        Flag = other.Flag;
    }
}

// Parents:
//   FUN_00401fe0 — embeds copy at node+0x0c during tree/map node init
//   FUN_00980160 — copies temp from FUN_00401d30 into local before map insert
```

---

## 5. Verdict

**accept-with-gaps** — adversarial checks fail to overturn CF/ABI/layout; product flag English and parent map type remain open. Mission Named_CalleeOf identity **rejected**.
