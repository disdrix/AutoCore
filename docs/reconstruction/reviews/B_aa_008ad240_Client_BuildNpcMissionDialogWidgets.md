# Review B (skeptical / adversarial): `Client_BuildNpcMissionDialogWidgets` @ `0x008ad240`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ad240` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (UF-011 residual — construct-only `+0x650` zero) |
| **Counterpart** | `reviews/A_aa_008ad240_Client_BuildNpcMissionDialogWidgets.md` |
| **Verdict** | **accept-with-gaps** on UI construct; **UF-011 zero site sealed High** as construct-only (not cancel/post-send) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Completes / accepts mission on build | Body would send C2S or mutate mission lists | **Falsified** — UI tree only; no net send |
| 2 | Lightweight / free to call anytime | Heavy MSXML + many `operator_new` | **Falsified** — race risk with CompleteObjective stands |
| 3 | Slot clear is “some UI flags” only | Index math might not be wire buffer | **Falsified for `0x194..0x19b`** — image `LEA [EDI+0x650]` zeros **exactly** Flush send span `0x20`; Prepare stamps `0x206E` there |
| 4 | Cancel-close re-zeros `+0x650` via this function | Close might CALL BuildWidgets again | **Falsified** — close `0x9c40` → `FUN_007fca10` → Flush (`vtbl+0x440`); BuildWidgets is **`vtbl+0x43c`**, not on close path |
| 5 | Flush or cancel clears buffer; BuildWidgets zero is redundant | Maybe multiple clear sites | **Partial** — other clears may exist in dtor/reuse, but **show→Prepare→HandleButton/close→Flush** chain: only BuildWidgets zeros; Flush does not; cancel does not |
| 6 | Name “Build…Widgets” hides wire role | Zeroing prepared opcode looks like packet logic | **Survives with note** — primary duty is chrome; zero is **construct hygiene** for the embedded packet buffer, not a send/prepare |

---

## 2. What the evidence actually proves

| Fact | Strength |
|---|---|
| Function at `0x008ad240` zeros 8 dwords from `this+0x650` | **Proven** (decompile ≡ image) |
| Span is `0x20` bytes (`+0x650`..`+0x66c`) | **Proven** |
| Vtable DATA `0x00a4a958` = this VA; offset from base = **`0x43c`** | **Proven** |
| Body xrefs are DATA-only (virtual) | **Proven** |
| Same object hosts Flush at **`+0x440`** | **Proven** (peer dual) |
| Prepare writes `0x206E` into `+0x650` at show | **Proven** (peer) |
| Flush sends from `+0x650` size `0x20` when nonzero | **Proven** (peer) |
| Cancel-close clears `+0x650` before flush | **Falsified** (UF-011 peer seal) |
| BuildWidgets runs on every dialog open in live client | **High static / runtime open** (virtual method; show/ctor path assumed) |
| No other zero of this buffer exists in client | **Medium** — sealed for show/close/send chain; full-image search of every store to `+0x650` not re-run this slice |

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Construct zeros prepared buffer | **High** | Misattribute UF-011 clear site |
| Buffer = C2S 0x206E prepared region | **High** | Wrong packet family |
| Construct-only in show/close/send lifecycle | **High (static)** | Claim cancel-safe falsely |
| MSXML race with turn-in FX | High | Client crash / UI corruption |
| Full child-slot English map | Medium | Wrong chrome ownership |
| “Only ever” zero site in entire EXE | Medium | Miss rare reinit helper |

---

## 4. Surviving contract for AutoCore

```
NPC mission dialog (client+0x1058, vtable 0x00a4a51c):
  vtbl+0x43c = Client_BuildNpcMissionDialogWidgets @ 0x008ad240
    on construct/build:
      zero dialog+0x650 .. +0x66c   // prepared MissionDialogResponse, size 0x20
      zero dialog+0x580 (byte)
      build i_d_npc_2d_* widget tree (items×4, close 0x9c40, …)

  vtbl+0x440 = FlushPreparedResponse  // does NOT zero +0x650 after send

Lifecycle (static):
  BuildWidgets  →  (later) Prepare stamps 0x206E at +0x650
               →  HandleButton may fill body (state 1)
               →  close/accept → FUN_007fca10 → Flush if opcode ≠ 0

UF-011:
  Cancel does NOT re-enter BuildWidgets zero.
  Closing after show can flush unfilled 0x206E.
  Server must tolerate cancel/unfilled body OR product must not assume filled-only.
```

---

## 5. Open questions (must not be papered over)

1. ~~Is `param_1[0x194]` really `+0x650`?~~ **Answered High:** `0x194*4=0x650`; image `LEA [EDI+0x650]`.
2. ~~Does BuildWidgets clear the prepared opcode buffer?~~ **Answered High:** yes, full `0x20`.
3. ~~Does cancel re-zero via this function?~~ **Answered High (static):** **no** — wrong vtable slot / wrong path.
4. Who **CALL**s `vtbl+0x43c` (ctor only vs show refresh)? Residual caller map.
5. Exact mapping of every child pointer (`param_1[0x1a0]` …) to product chrome names.
6. Runtime: does rebuild-on-reopen always re-zero before Prepare?

### 5.1 UF-011 adversarial residual — **sealed at this VA**

Attack “maybe BuildWidgets runs on cancel and clears stale 0x206E” fails:

- Close dispatch uses **`vtbl+0x440` (Flush)**, adjacent to but **≠** **`+0x43c` (this)**.
- Image/decomp of this body show zero **only at entry**, before chrome build — not a teardown path.
- Peer Flush has **no** post-send store to `+0x650`.

Do **not** document “cancel clears prepared opcode.” Document: **zero only at BuildWidgets construct; cancel can flush unfilled 0x206E.**

---

## 6. Verdict

**accept-with-gaps.**

Adversarial position after UF-011 residual: **`+0x650` clear site for the prepared buffer is this function, construct-only.** That **strengthens** (does not reopen) UF-011: cancel-close remains unsafe for unfilled 0x206E. Full MSXML tree detail and runtime remain gaps — do not upgrade to clean **accept**.
