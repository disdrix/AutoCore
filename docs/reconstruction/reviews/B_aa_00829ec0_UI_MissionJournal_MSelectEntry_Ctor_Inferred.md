# Review B (skeptical / adversarial): `aa_00829ec0` UI_MissionJournal_MSelectEntry_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829ec0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ7R-E) |
| **Counterpart** | `reviews/A_aa_00829ec0_UI_MissionJournal_MSelectEntry_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `read_memory` + callers/xrefs + assembly context. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a pure thiscall (`ECX=this`) | **Falsified** — stack this (`[esp+0x14]` after SEH); **`ret 4`** |
| 2 | Object size is free-form / not 0x510 | **Falsified** — all 4 call sites `push 0x510` before `operator_new` |
| 3 | Function grants or fails missions | **Falsified** — ctor + ReloadInterface only; no mission manager callees |
| 4 | XML string is decorative / wrong path | **Falsified** — push of `0x00a74978` + confirmed string bytes |
| 5 | Tail fields are unrelated to chrome peer | **Falsified** — `+0x4FC`/`+0x4FD`/`+0x504..0x50C` match sealed `BuildMSelectChrome` |
| 6 | Multiple independent callers | **Falsified** — sole function caller is journal update (4 sites) |
| 7 | `+0x500=-1` is a confirmed mission-id store | **Unproven product name** — sentinel sealed; English open (gap retained) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 4 + stack this | **High** | Wrong ctor calling convention |
| Size 0x510 | **High** | Heap under/over-alloc |
| Journal entry role | **High** | Mis-wire UI rebuild |
| Field offset map | **High** | Chrome builder writes wrong slots |
| Product class name | Medium | Naming only |
| Runtime layout parity | Open | Server-irrelevant client UI |

---

## 3. Cross-check against raw + bytes

```
SEH → FUN_00792d20(this)
*this = 00a74484
[this+0x4FD]=0; [this+0x4FC]=0
[this+0x500]=-1; [this+0x504..0x50C]=0
ReloadInterface("i_d_npc_2d_btn_mselect.xml")
return this; ret 4
```

Do **not** port as ECX-thiscall without stack adjust. Do **not** treat as mission logic.

---

## 4. Surviving contract for AutoCore

```csharp
// MissionJournalMSelectEntry* Ctor(MissionJournalMSelectEntry* self)
// sizeof = 0x510; base = NDUIContainerPanel; skin = i_d_npc_2d_btn_mselect.xml
// +0x4FC category, +0x4FD complete, +0x500 selection(-1), +0x504/508/50C children
```

Used when rebuilding Active/New mission lists under dialog state 3.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks confirm ctor contract and journal-only use. Residual: product name, vtbl catalog, runtime.
