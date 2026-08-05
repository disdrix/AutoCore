# Review B (skeptical / adversarial): `aa_00438c40` Sto_UnserialFactoryMapA_GetInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00438c40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W35-D) |
| **Counterpart** | `reviews/A_aa_00438c40_Sto_UnserialFactoryMapA_GetInstance_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` on **own VA** (+ atexit thunk bytes + caller decompile for role attacks). No ledger edits. No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function **is** the factory insert/log path | Body only once-init + return pointer; no strings, no `vog_LogMessage` | **Falsified** — getter only; insert is `FUN_004449b0` |
| 2 | ECX-thiscall / returns method result on caller this | No ECX this; `MOV EAX, imm32 &static`; plain RET | **Falsified** — **cdecl void→ptr** |
| 3 | Re-constructs NestedHash every call | Once-flag `DAT_00d1fd40&1`; cold path only | **Falsified** — Meyers once-init |
| 4 | Returns creator **function pointer** or tag int | Always `EAX = 0x00d1fd18` | **Falsified** — returns **bag\***; creators at map-node `+0xc` in callers |
| 5 | Same object as MapB `0x00438ca0` | Different statics: A=`d1fd18`/flag`d1fd40` vs B=`d1fcec`/flag`d1fd14` | **Falsified if conflated** |
| 6 | atexit runs NestedHash deep dtor / frees sentinel | Thunk JMP → `0x4493eb` = **`RET 4`** | **Clarify** — process-exit **no-op** free |
| 7 | Once-flag is full dword equality to 0 | Bytes: `TEST …, AL` / `OR …, EAX` with 1 → **bit0 only** | **Sealed bit0** |
| 8 | Scaffold gfxBody name is product role | Zero graphics; exclusive Sto factory callers | **Over-narrow/wrong** — reject |
| 9 | Bag size is full factory class `0x220` etc. | Ctor is NestedHash span **0x28** (W34-E); flag at `+0x28` | **Falsified** — bag is NestedHash shell only |
| 10 | Decompiler SEH locals change return | Epilogue always loads imm `&DAT_00d1fd18` | **No** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Singleton address `DAT_00d1fd18` | **High** | Ports allocate per-call → lost registrations |
| Once-flag bit0 @ `DAT_00d1fd40` | **High** | Double ctor / double atexit |
| NestedHash 0x10 ctor callee | **High** | Wrong bag layout |
| No insert/log side effects in body | **High** | Ports invent factory logic inside getter |
| Return is bag pointer not int | **High** | Callers use EAX as tag → wrong branch |
| Sto map-A product English | **Medium** | Doc only (`_Inferred`) |
| atexit free semantics | **High** (no-op bytes); product "why" open | Over-porting a free that retail skips |
| Thread-safe init | **None claimed** | Dual init race if multi-thread early boot |

---

## 3. Cross-check against raw / bytes

```
raw decompile:
  if ((DAT_00d1fd40 & 1) == 0) {
    DAT_00d1fd40 |= 1;
    FUN_00457ac0(&DAT_00d1fd18);
    atexit(LAB_009c3310);
  }
  return &DAT_00d1fd18;

bytes:
  TEST [00d1fd40], 1 ; JNZ skip
  OR   [00d1fd40], 1
  CALL 00457ac0(&00d1fd18)
  CALL atexit(009c3310)
  MOV  EAX, 00d1fd18 ; RET
```

Clean must **not** invent:

- Duplicate-tag logging / `stoAbstractUnserializationFactory.h` strings
- Stack tag parameters
- Returning `*(bag+8)` instead of bag
- Full NestedHash free in atexit
- Graphics / gfxBody role

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact port of 0x00438c40
static NestedHash0x10 g_stoFactoryMapA;   // DAT_00d1fd18, size 0x28
static int g_stoFactoryMapAOnce;          // DAT_00d1fd40 — use bit0 only

static NestedHash0x10* Sto_UnserialFactoryMapA_GetInstance()
{
    if ((g_stoFactoryMapAOnce & 1) == 0)
    {
        g_stoFactoryMapAOnce |= 1;
        NestedHash_Ctor_Sentinel0x10(&g_stoFactoryMapA); // FUN_00457ac0
        // atexit: no NestedHash free required for process exit
    }
    return &g_stoFactoryMapA;
}

// Callers (separate units):
//   insert: FUN_004449b0 uses map; compares *(map+8) sentinel
//   lookup: FUN_00437b00 invokes creator at node+0xc
```

**Port traps to reject:**

- Sharing MapA and MapB statics
- Treating getter as insert API
- ECX-thiscall
- Atomic once without evidence

---

## 5. Verdict

**accept-with-gaps** — adversarial checks hold for ABI/CF/statics/call role. Remaining gaps are product English for tag domains and unowned map ops — not body fidelity.
