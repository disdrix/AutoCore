# Review A (reconstruction fidelity): `aa_004b6fc0` NDSpecialFX_RequestPlayAudioList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b6fc0` |
| **VA** | `0x004b6fc0` |
| **Canonical name (Ghidra)** | `FUN_004b6fc0` |
| **Proposed name** | `NDSpecialFX_RequestPlayAudioList_Inferred` (**High** role; product symbol absent; string `"Requesting play %s\n"`) |
| **Prior scaffold alias** | `Mission_Requesting_play_s_004b6fc0` — string-only |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004b6fc0_NDSpecialFX_RequestPlayAudioList_Inferred.md` |
| **System** | `client-fx` / NDSpecialFX host audio list |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Activate-path play of the NDSpecialFX audio-request list** at `this+0x1F8` (gated by non-zero count/flag at `this+0x1FC`).

For each intrusive list node while `this+0x1FC != 0`:

1. Payload `p = node[2]` (0xC8-byte / `0x32` dword pod — matches clone size in `FUN_004a0b90` list copy).
2. Copy `0x32` dwords of `*p` onto a stack scratch (`auStack_dc`).
3. `FUN_00720d40()` then `FUN_00720670()` — request/start play helpers (args mostly lost in decompiler; deactivate sibling uses `FUN_00720d40(p,1)` + `FUN_007203b0(p,1)`).
4. Debug log via `FUN_007a4480` with format **`"Requesting play %s\n"`** and payload pointer as the `%s` source.

Invoked only on the **activate** branch of host flag cascade `FUN_004b8dc0` (after `FUN_004b7e50`), and from weather tick `FUN_00555f10` when an active weather FX list is non-empty.

**Not** a network send, not mission logic, not the deactivate stop walk (that is the zero-flag path of `004b8dc0` on the same list).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` + `analyze_function_complete` @ `0x004b6fc0` |
| Function meta | body `004b6fc0`–`004b7023` |
| Raw | `docs/reconstruction/raw/aa_004b6fc0_FUN_004b6fc0.md` |
| Annotated | `docs/reconstruction/raw/aa_004b6fc0_FUN_004b6fc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004b6fc0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004b6fc0_FUN_004b6fc0.md` |
| Sibling dual | `reviews/A_aa_004b8dc0_FUN_004b8dc0.md` (activate → this) |
| Related clone | `FUN_004a0b90` copies `+0x1F8` entries with `operator_new(200)` / `0x32` dwords |

**This pass:** live decompile; callers/callees; sibling activate CF. **Not performed:** Launcher, runtime, bit-exact image diff, ledger updates.

---

## 3. Signature

```c
// fastcall/thiscall via ECX host; no stack args in decompiler
void __fastcall NDSpecialFX_RequestPlayAudioList_Inferred(void *fx /* ECX */);
```

`analyze_function_complete`: `param_1` in register ECX (`register:00000004`). Sibling `004b8dc0` calls with host as `this`.

---

## 4. Callers (2) / callees (3)

| Caller | VA | Role |
|---|---|---|
| `FUN_004b8dc0` | `0x004b8dc0` / xref `004b8e49` | Activate branch after `FUN_004b7e50` |
| `FUN_00555f10` | `0x00555f10` / xrefs `00556415`, `0055643c` | Weather/env FX tick — request play when list gated |

| Callee | Role |
|---|---|
| `FUN_00720d40` | Audio/request setup (also deactivate with arg `1`) |
| `FUN_00720670` | Start/play companion (activate only) |
| `FUN_007a4480` | Debug printf family — `"Requesting play %s\n"` |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Gate `*(this+0x1FC) != 0` | Yes |
| List walk `*head` until head @ `this+0x1F8` | Yes |
| `0x32` dword payload copy to stack | Yes |
| `00720d40` → `00720670` → log → next node | Yes |
| Empty/zero gate → return | Yes |

No SEH. Leaf-ish worker (three external callees only).

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Host is NDSpecialFX-sized / same layout as `004b8dc0` / dtor lists | **High** | Shared `+0x1F8`/`+0x1FC` with activate + `004b85d0` teardown |
| List payload size `0xC8` (`0x32` dwords) | **High** | Copy loop + `004a0b90` `operator_new(200)` |
| Activate-only play (not stop) | **High** | Sibling deactivate uses `007203b0` not `00720670` |
| Debug string labels play request | **Confirmed** | literal in body |
| Product C++ name | **Tentative** | keep `_Inferred` |
| Exact ABI of `00720d40`/`00720670` args (stack copy vs original ptr) | **Probable** | decompiler elides args; stack copy may be for name/`%s` only |

---

## 7. Gaps / open

1. Product symbol for host method.
2. Full audio entry layout at payload (name offset for `%s`).
3. Precise arg packing into `00720d40` / `00720670` (need targeted read of call sites if porting audio).
4. Runtime play verification not run.

**Verdict:** **accept-with-gaps** — CF + list offsets High; audio helper arg detail Probable.
