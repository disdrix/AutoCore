# Review B (skeptical / adversarial): `aa_008ac3f0` Client_NpcMissionDialogHost_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac3f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-107) |
| **Counterpart** | `reviews/A_aa_008ac3f0_Client_NpcMissionDialogHost_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + callers/xrefs + `read_memory` only (**no** `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is ShowNpcMissionDialog / packet path | **Falsified** — ctor only; no 0x206E, no mission def lookup |
| 2 | Standard `__thiscall` ECX-this for outer body | **Falsified as exclusive** — stack this → EDI; **`RET 4`**; ECX set only for callees |
| 3 | String name `Mission_i_d_npc_xml_*` is product plate | **Falsified** — string is skin path only; class is vtable `0x00a4a51c` host |
| 4 | Multiple callers / vtbl DATA entry for ctor | **Falsified** — **1** UNCONDITIONAL_CALL from `FUN_0093e7e0` @ `0x0093f420` |
| 5 | Alloc size unknown / generic UI | **Falsified** — caller `operator_new(0x748)`; store `client+0x1058` |
| 6 | Builds full widget tree here | **Falsified** — only response strip via `FUN_008ac110`; full tree is BuildWidgets `+0x43c` later |
| 7 | `param[400]=1` is unrelated magic | **Falsified** — peer dual `008ac110` treats `+0x640` as **columns** (clamp ≥1) |
| 8 | Virtual `+0x34C` is Flush/BuildWidgets | **Falsified** — Flush is `+0x440`, BuildWidgets `+0x43c`; slot dword is **`0x00791dc0`** |
| 9 | Name is product-sealed without `_Inferred` | **Not supported** — no PDB; `_Inferred` required |
| 10 | Ghidra `void` signature is authoritative | **Falsified** — analyze warns undefined return; image returns **EAX=this**, decompile `int*` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Host ctor role + `client+0x1058` | **High** | Wrong dialog table slot |
| Vtable `0x00a4a51c` install | **High** | Breaks Flush/BuildWidgets linkage |
| ABI stack-this / RET 4 | **High** | Bad hooks / wrong convention |
| XML skin + response strip call order | **High** | Broken first-paint chrome |
| Columns/mode defaults | **High** (cross-peer) | Layout div0 / mode offsets |
| Transform block as “UI basis” English | **Med** | Cosmetic naming only |
| Product class spelling | **Low** | Naming only |
| Virtual `00791dc0` semantics | **Low–Med** | Post-load side effects unknown |

---

## 3. Cross-check contract

```
Client_NpcMissionDialogHost_Ctor_Inferred(self*):  // stack; RET 4; EAX=self
  FUN_0087b890(self, 0)
  *self = vtbl 0x00a4a51c
  basis[+0x584..] = three (0,0,0,1) rows
  zero select dwords; +0x4FC=0xC; +0x500=1; +0x63C=1; +0x640=1; +0x648=0; …
  FUN_008ab0a0()                         // ECX=self
  NDUIWindow_ReloadInterface("i_d_npc.xml")
  UI_MissionDialog_BuildResponseButtons_Inferred()  // EDI=self
  call self->vtbl[+0x34C]()              // FUN_00791dc0
  return self
```

Caller:

```
FUN_0093e7e0:
  p = operator_new(0x748)
  if p: p = FUN_008ac3f0(p)
  client[+0x1058] = p
```

Clean must **not** invent: mission accept/fail packets, journal list fill, HideMissionDialogIfOpen (`+0x107c`), or claim product PDB name.

---

## 4. Surviving contract for AutoCore

```c
// Client UI only — construct NPC mission dialog host (size 0x748)
// Store at client+0x1058. Vtable 0x00a4a51c.
// Stack this*, RET 4, EAX=this.
NpcMissionDialogHost* Client_NpcMissionDialogHost_Ctor_Inferred(
    NpcMissionDialogHost* self);
```

Port notes:

- Keep call order: base → vtbl → defaults → field zero → XML → response buttons → virtual.
- Default **columns = 1**, **mode = 0**, chrome id **0x0C**.
- Do not merge with ShowNpcMissionDialogUI (`0x009438f0`) or BuildWidgets (`0x008ad240`).

---

## 5. Verdict

**accept-with-gaps** — adversarial attacks on show/packet/thiscall/multi-caller/wrong-vtbl-slot/product-string-name **fail**; remaining gaps are product English + nested non-OWN plates + runtime. Terminal **false**.
