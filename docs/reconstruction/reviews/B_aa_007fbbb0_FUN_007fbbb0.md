# Review B (skeptical / adversarial): `aa_007fbbb0` FUN_007fbbb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbbb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (wave8 OWN-ONLY dual — Grab path) |
| **Counterpart** | `reviews/A_aa_007fbbb0_FUN_007fbbb0.md` |
| **Live re-decompile** | Ghidra MCP 2026-07-29 force + decompile — body matches raw |
| **read_memory / p-code** | Offsets verified in body bytes; ESI-based loads confirmed |
| **Verdict** | **accept-with-gaps** on CF / host ESI / offset map; **reject** overclaims that this unit packs or sends Grab |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Body is Grab **packet** builder (`0x2034` / size `0x20`) | **Falsified** — no opcode immediate, no stack packet buffer, no send |
| 2 | Sets busy flags `DAT_00d1a8f6` / `DAT_00d1b4b0` | **Falsified** — no global stores in body |
| 3 | Always runs side effects | **Falsified** — triple gate (held null / vtbl+0xd0 false / `+0x2b0` null) → silent ret |
| 4 | Stack args complete the ABI | **Broken as portable formals-only** — live **ESI** host required (`unaff_ESI`) |
| 5 | ESI is always `DAT_00d1a840` | **Survives for Grab FromGrid/Hardpoint** (`MOV ESI,0xd1a840`); **not universal** — `FUN_007ff3d0` uses `MOV ESI,EBX` |
| 6 | Exclusive Grab helper | **Weakened** — 11 call sites; multiple non-Grab-named parents |
| 7 | `vtbl+4(0)` is always destructor | **Open** — pattern matches MSVC releasing dtor slot, but not proven without concrete vtable |
| 8 | Copies always run | **Falsified** — only when `*(ui+0x514/0x518) > 0` (signed `jg` style: `0 < field`) |
| 9 | Clean invents CF | **Falsified** — clean ≡ raw ≡ live re-decompile |
| 10 | Function returns status | **Falsified** — void / no useful EAX; pure side effects |
| 11 | `host+0x113c` written null here | **Falsified** — body never stores to `+0x113c` |
| 12 | UI root is `*(host+0xf40)` not `**(host+0xf40)` | **Falsified** — double load: `** (host+0xf40)` then vtbl |

---

## 2. Surviving contract (minimal hard reading)

```
// ABI
//   ESI = client host*  (layout: +0x113c held*, +0xf40 → T* → ui_root*)
//   no stack args observed in body
//   return: void

held = *(host + 0x113c)
if held == null: return

if held->vtbl[0xd0/4]() == 0: return     // CALLIND gate
if *(held + 0x2b0) == 0: return

ui = **(host + 0xf40)
ui->vtbl[0xb0/4](held)                   // thiscall ui, arg held
held->vtbl[0x4/4](0)                     // release/dtor-style
ui->vtbl[0x1c8/4](0)
ui->vtbl[0x3c0/4](0)

if *(ui + 0x514) > 0:  *(ui + 0x498) = *(ui + 0x514)
if *(ui + 0x518) > 0:  *(ui + 0x49c) = *(ui + 0x518)
return
```

**Cannot be attacked away:** gate order, CALLIND sequence, conditional copies, ESI host, absence of packet/busy work.

---

## 3. Placement in Grab path (adversarial split of duties)

| Stage | Owner | Sealed here? |
|---|---|---|
| Optional selection pre-clear (EDI) | FromGrid body | **No** (parent) |
| **Held UI object clear** | **this unit** | **Yes** (CF) |
| Busy gate | FromGrid / Hardpoint | **No** |
| Pack `0x2034` / send | FromGrid / Hardpoint | **No** |
| S2C GrabResponse / split apply | `aa_00811be0` | **No** |

Attack “Grab helper packs C2S” **fails**. Attack “Grab helper clears local held UI state when present” **holds** as the minimal purpose consistent with CF + call placement.

---

## 4. What still fails seal

| Topic | Why open |
|---|---|
| Vtbl target functions | CALLIND only; resolve needs concrete object vtables (other VAs) |
| Field pair semantics `0x514/0x498`, `0x518/0x49c` | Integers copied if positive; no names in body |
| Who nulls `+0x113c` after release | Not this function |
| Full parent set renames | Several xrefs still FUN_/unnamed |
| Runtime proof | No CE/session capture this dual |
| Official rename | Parent-seed alias only; do not over-rename |

---

## 5. Alternate interpretations

### Minimal (accepted)

Thin **ESI-host method**: if a held inventory object is present and passes two gates, detach it from the UI root, release it, zero two UI vfuncs, optionally sync two integer field pairs. Used early in Grab senders and other client UI paths.

### Rejected overclaims

1. “This is the InventoryGrab packer” — parents own pack/send.
2. “Always clears on every Grab” — no-op when gates fail or held null.
3. “ESI is only DAT_00d1a840” — layout-compatible host; Grab sites load that global, others pass EBX host.
4. “Return code indicates success” — void.
5. “Nulls held pointer itself” — no store to `+0x113c`.

### Competing stories still viable for labels only

- `+0x113c` = cursor item vs drag ghost vs modal selection object — **structure same**, label open.
- `vtbl+0xd0` = IsValid / IsVisible / CanRelease — **bool gate only** sealed.
- Field pairs = window metrics vs selection indices — **copy-if-positive** sealed.

---

## 6. Fidelity checklist (A dual)

| Check | Result |
|---|---|
| Live decompile ≡ raw | **Pass** |
| Clean CF ≡ raw | **Pass** |
| Offsets in read_memory body | **Pass** |
| Named direct callees claimed | **None** (correct) |
| Packet/busy claims in clean | **Must not** appear — scaffold is honest |
| Own-VA scope respected | **Yes** — no callee bodies required for CF seal |

---

## 7. Open questions

1. Resolve concrete `held` / `ui` vtables at runtime or via constructor sites.
2. Trace who writes `host+0x113c` and who nulls it after `vtbl+4(0)`.
3. Name remaining 11 parents once functions exist in DB.
4. CE: grab with empty held vs with held — confirm no-op vs full path.

**Verdict:** Dual A’s **accept-with-gaps** is correct. Seal CF + ESI host + offsets + Grab pre-placement. Reject any claim that this VA builds or sends InventoryGrab. Labels for vfuncs/fields remain adversarial-open.
