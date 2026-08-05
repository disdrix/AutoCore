# Review B (skeptical / adversarial): `aa_008847f0` CDlgTrade2d_CreateChildWidgets

| Field | Value |
|---|---|
| **Stable ID** | `aa_008847f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008847f0_CDlgTrade2d_CreateChildWidgets.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Sends trade C2S (add item / credits / approve / complete) | Callee list is new/ctor/attach/XML/grid-refresh only; no `Client_Send*` | **Falsified** — pure UI construction |
| 2 | Full decompile body is authoritative | Live `decompile_function` / `force_decompile` → **Overlapping input varnodes** | **Do not seal C body** — use asm/signature only |
| 3 | Direct CALL callers exist | `get_function_callers` empty; only DATA `@ 0x00a56ad8` | **Vtable dispatch only** |
| 4 | Owner flag 6 means “cargo” | Inventory system maps type **5** trade / **6** other on DropResponse; flag written on **them** inv object only | **Tentative product English** — value **6** High; English label from drop map not re-proven here |
| 5 | `host+0x548` keeps offer_them forever | Three writes: offer_them → balance_title → balance | **Falsified durable offer_them slot** — final host `+0x548` is balance; offer_them only in child tree |
| 6 | Creates credit **them** edit boxes like you | Only `edt_credits_you_1..4` via `FUN_00795f20`; them side is icon + `wnd_credits_them_*` windows | **Do not invent them edit boxes** |
| 7 | Invents server trade inventory layout | Only binds pre-existing `+0xce0` inventory pointers | **Survives as bind-only** |
| 8 | Name invents gameplay | Name from trade XML prefix `i_d_t_2d_*` + registry | **Survives** as client UI factory |

---

## 2. Cross-check: live recovery ≡ prior structural capture

Prior 2026-07-23 capture (decompiler-blocked scaffold) listed partial callees + XML set. Live 2026-07-29 pass:

| Check | Result |
|---|---|
| Decompiler still blocked | **Yes** — same error |
| 41 `i_d_t_2d_*` strings | **Confirmed** via `get_function_signature` + globals audit |
| Callees include grids / SetOwnerFlag / button ctors | **Confirmed** |
| New: full host `MOV [EDI+off]` map | **Added** from `disassemble_function` |
| New: widget ids 40000–40005 | **Sealed** from immediates |
| New: `+0x548` overwrite chain | **Sealed** |
| Clean plate must remain structural | **Yes** — not bit-identical C |

No material contradiction with prior role claim; depth improved via asm.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| UI CreateChildWidgets role | **High** | Wrong system ownership |
| No network in this VA | **High** | False protocol coupling |
| Dual grid slots + IDs | **High** | Trade UI bind bugs |
| Local inv `DAT_00d1b6d8+0xce0` | **High** | Wrong inventory source |
| Partner via `this+0x510` | **High** | Them pane empty/wrong |
| Owner flag value **6** | **High** | Peer grid ownership wrong |
| Owner flag English “trade type” | **Tentative** | Doc confusion only |
| `+0x548` durable meaning | **High as last-write** | If later code expects offer_them at `+0x548` |
| Full child-order vs layout engine | **Open** | Visual only |
| Server impact | **None** | N/A |

---

## 4. Surviving contract for AutoCore

```
// Client-only CDlgTrade2d::CreateChildWidgets (thiscall, void)
// Dispatch: vtable DATA 0x00a56ad8 → 0x008847f0
//
// Preconditions (not set by this unit):
//   this is an already-constructed trade dialog host
//   this+0x510 = partner root object* (or null) for them inventory at +0xce0
//   DAT_00d1b6d8+0xce0 = local player trade inventory* when trading
//
// Body:
//   FUN_00792600(this)  // wipe/rebuild children
//   for each chrome/button/grid/edit/gauge:
//     operator_new(size) → specialized_ctor → host.vtbl[+0xa8] attach
//     load matching i_d_t_2d_*.xml; optional alpha 0.5f
//     store host field pointer (see A field map)
//   inv_you (+0x588): bind DAT_00d1b6d8+0xce0, id 40002, refresh
//   inv_them (+0x58c): bind (this+0x510)?->+0xce0, id 40003, refresh,
//                      SetOwnerFlag(inv, 6) if inv non-null
//   this+0x49c = 40000; clear +0x50c/+0x50d; finalize vtbl +0x448 / +0x34c
//
// Does NOT: send trade packets, approve/complete, move items.
// Click/network live in other VAs.
```

---

## 5. Open questions (residual)

1. Unblock Ghidra decompiler (varnode overlap) for bit-level C plate.
2. Producer of `this+0x510` and open-trade path that installs the vtable host.
3. Whether any later code still expects offer_them at `+0x548` (unlikely given overwrite).
4. Product names for specialized ctors and host vtbl slots.
5. Runtime: confirm flag-6 interaction with DropResponse inventoryType switch (5 vs 6).

**Verdict:** Adversarial checks clear send/overclaim and force asm-only seal. Construction contract holds. **accept-with-gaps.**
