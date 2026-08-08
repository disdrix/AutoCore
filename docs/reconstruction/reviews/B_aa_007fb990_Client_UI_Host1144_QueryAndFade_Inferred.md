# Review B (skeptical / adversarial): `aa_007fb990` Client_UI_Host1144_QueryAndFade_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fb990` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY dual B **R12-007** — live Ghidra) |
| **Counterpart** | `reviews/A_aa_007fb990_Client_UI_Host1144_QueryAndFade_Inferred.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present (create/seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is OnKeyDown-only helper | Named_CalleeOf scaffold | **Falsified** — **15** CALL xrefs across mode latch, skill cancel, interact, packet UI, etc. |
| 2 | ECX thiscall host | Copy parent `00914c60` ABI | **Falsified** — host in **ESI**; body never takes ECX host; plain `RET` |
| 3 | Stack args / `RET 4` | Wrapper style | **Falsified** — `C3`; zero stack params |
| 4 | Unconditionally fades dialog | Always-run | **Falsified** — three early-outs (null / query false / state==-1) |
| 5 | Float is 0.5f (sibling sites) | Nearby `0x3f000000` on other slots | **Falsified for this body** — imm is **`0x3dcccccd` = 0.1f** |
| 6 | Operates on cursor host `DAT_00d1b9a8` | Parent dual host pattern | **Falsified** — only `ESI+0x1144`; no `DAT_00d1b9a8` load |
| 7 | Writes drive / latch / skill pending | input-drive-control membership | **Falsified** — pure UI virtuals on one slot; no `+0x493` / `+0x30c0` / park |
| 8 | Product English sealed | No string / PDB in body | **Fail** — `_Inferred` only |
| 9 | Ready for runtime Confirmed | Matrix | **Fail** — no Launcher; Terminal false |
| 10 | Slot is freeform pointer | Install plate unknown | **Falsified for install** — CreateNDUIDialogs writes `+0x1144` via `FUN_007b5dd0` |

---

## 2. Decisive dataflow

```
// entry: ESI = client UI host (callers: often MOV ESI, 0x00d1a840)
obj = *(ESI + 0x1144)
if obj == 0: goto ret
ECX = obj
AL  = [ECX->vtbl + 0xd0]()     // query bool
if AL == 0: goto ret
ECX = obj
EAX = [ECX->vtbl + 0xe8]()     // state/index
if EAX == -1: goto ret
ECX = obj
push 0x3dcccccd                 // 0.1f  (second arg)
push 0                          // first arg
CALL [ECX->vtbl + 0xfc]         // thiscall fade/transition
ret:                            // C3
```

Live decompile 2026-08-05 ≡ 2026-07-23 raw CF. Asm seals ESI host + PUSH order + plain RET.

---

## 3. Adversarial polarity vs parent / siblings

| Unit | VA | Role | Drive park |
|---|---|---|---|
| **This** Host1144 QueryAndFade | `007fb990` | UI slot fade under gates | **none** |
| Parent SetModeLatch493 | `00914c60` | latch + calls this then Stop | park only on clear via `00914c20` |
| Sibling fade sites | e.g. `007fc890` | other host slots + `0.5f` | none (different imm) |

Do **not** merge:
- with `00914c60` (wrapper owns latch/park),
- with cursor host `DAT_00d1b9a8` notify path,
- with Named_CalleeOf OnKeyDown-only scaffold.

---

## 4. Caller inventory (adversarial count seal)

**15** UNCONDITIONAL_CALL xrefs (`get_function_xrefs`):

| Site | Function | ESI prep (context) |
|------|----------|--------------------|
| `00914c9e` | `FUN_00914c60` (parent dual) | `MOV ESI,0xd1a840` |
| `00911199` | `Client_Input_OnKeyDown_MatchAction` | `MOV ESI,0xd1a840` after Prompt(-1) |
| `00925279` | `FUN_009251d0` | `MOV ESI,0xd1a840` after Prompt(-1) |
| `007fc896` | `FUN_007fc840` | ESI already host method |
| `007fc9f2` | `FUN_007fc9b0` | ESI host |
| `007fd1a7` | `FUN_007fd090` | ESI live across site |
| `00935504` | `FUN_00935430` | ESI host |
| `0090e419` | `FUN_0090e3c0` | `MOV ESI,0xd1a840` |
| `0090e18b` | (caller of site) | `MOV ESI,0xd1a840` |
| `008a1f21` | `FUN_008a1e60` | `MOV ESI,0xd1a840` |
| `0082914c` | (inline site) | `MOV ESI,0xd1a840` |
| `008c4c37` | (inline site) | `MOV ESI,0xd1a840` |
| `0087b942` | (inline site) | `MOV ESI,0xd1a840` |
| `0088ca71` | (inline site) | `MOV ESI,0xd1a840` |
| `00942427` | `FUN_009423b0` | `MOV ESI,EBX` (client this) |

**Not** a single-caller leaf. Scaffold name **OnKeyDown-only** is rejected.

---

## 5. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI host + plain RET | **High** | Wrong call ABI |
| Triple-gate CF | **High** | Spurious fade |
| Imm `0.1f` args | **High** | Wrong fade duration/scale |
| Slot `+0x1144` NDUI install | **High** | Wrong object family |
| Shared multi-caller cleanup | **High** | Missed cancel paths |
| Product dialog / slot English | **Open** | Naming only |
| Runtime | **Open** | Parity residual |

---

## 6. Surviving contract for AutoCore

```
Host1144_QueryAndFade(host /* ESI */):
  // no stack args; plain ret
  obj = host.slot_1144
  if !obj: return
  if !obj.query_d0(): return
  if obj.state_e8() == -1: return
  obj.fade_fc(0, 0.1f)
```

**Port notes:**
- Implement as **ESI-host free function / custom convention**, not ECX thiscall on host.
- Gate all three conditions; do not always fade.
- Pair with CreateNDUIDialogs install of `+0x1144`; do not invent drive/latch side effects.
- Supersede `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007fb990`.

**Verdict:** **accept-with-gaps** — adversarial single-caller / thiscall-host / unconditional-fade / cursor-host / drive-side-effect claims closed; product English + runtime open.
