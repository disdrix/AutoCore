# Review B (skeptical / adversarial): `aa_00438ca0` Sto_UnserialFactoryMapB_GetInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00438ca0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W35-D) |
| **Counterpart** | `reviews/A_aa_00438ca0_Sto_UnserialFactoryMapB_GetInstance_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` on **own VA** (+ atexit thunk + caller decompile). No ledger edits. No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Same singleton as MapA (`0x00438c40`) | Distinct bag `DAT_00d1fcec` and flag `DAT_00d1fd14`; exclusive different callers | **Falsified if merged** |
| 2 | Is insert / lookup / creator invoke | Body is getter only | **Falsified** — callers `FUN_00444a40` / `FUN_00437c90` |
| 3 | ECX-thiscall | No ECX this; plain RET; `MOV EAX, imm` | **Falsified** — cdecl void→ptr |
| 4 | Reconstructs every call | Once-flag bit0 | **Falsified** — Meyers |
| 5 | atexit frees NestedHash | JMP to `0x4493eb` RET4 | **Clarify** — **no-op** free |
| 6 | gfxBody product role (scaffold) | Sto header string on exclusive insert caller | **Reject scaffold** |
| 7 | Different NestedHash node size than MapA | Same `FUN_00457ac0` call | **Falsified** — both **0x10** |
| 8 | Once-flag full dword | `TEST`/`OR` with 1 | **bit0 only** |
| 9 | Returns sentinel pointer (`bag+8`) | `MOV EAX, &DAT_00d1fcec` | **Falsified** — returns **bag base**; callers load `+8` |
| 10 | Shares once-flag with bag C (`FUN_0044fee0`) | Flag C is `DAT_00d1fce8`; B is `d1fd14` | **Falsified if conflated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Singleton `DAT_00d1fcec` | **High** | Cross-map registration corruption |
| Once-flag bit0 `DAT_00d1fd14` | **High** | Double ctor |
| Twin of MapA (not same object) | **High** | Silent map collision |
| NestedHash 0x10 ctor | **High** | Layout mismatch |
| Sto factory map B role | **High** (exclusive callers) | Wrong subsystem plate |
| Product English "B" domain | **Medium / Inferred** | Doc only |
| atexit no-op | **High** (bytes) | Port invents free |

---

## 3. Cross-check against raw / bytes

```
raw:
  if ((DAT_00d1fd14 & 1) == 0) {
    DAT_00d1fd14 |= 1;
    FUN_00457ac0(&DAT_00d1fcec);
    atexit(LAB_009c3300);
  }
  return &DAT_00d1fcec;

bytes: TEST/OR [d1fd14],1 ; CALL 457ac0(&d1fcec) ; atexit(9c3300) ; MOV EAX,d1fcec ; RET
```

Clean must **not** invent:

- Shared storage with MapA or bag C
- Insert/log strings in this body
- Returning `*(bag+8)`
- NestedHash free on atexit
- gfxBody naming

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact port of 0x00438ca0 — SEPARATE from MapA
static NestedHash0x10 g_stoFactoryMapB;   // DAT_00d1fcec
static int g_stoFactoryMapBOnce;          // DAT_00d1fd14 bit0

static NestedHash0x10* Sto_UnserialFactoryMapB_GetInstance()
{
    if ((g_stoFactoryMapBOnce & 1) == 0)
    {
        g_stoFactoryMapBOnce |= 1;
        NestedHash_Ctor_Sentinel0x10(&g_stoFactoryMapB);
    }
    return &g_stoFactoryMapB;
}
```

**Port traps:** merging A/B maps; using MapA once-flag; treating as thiscall method.

---

## 5. Verdict

**accept-with-gaps** — adversarial separation from MapA holds; body sealed; product tag-domain English open.
