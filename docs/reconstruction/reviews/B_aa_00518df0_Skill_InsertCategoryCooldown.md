# Review B (skeptical / adversarial): `aa_00518df0` Skill_InsertCategoryCooldown

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518df0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual; prior 2026-07-23) |
| **Counterpart** | `reviews/A_aa_00518df0_Skill_InsertCategoryCooldown.md` |
| **Verdict** | **accept-with-gaps** — prior opens on clock/callers **closed or narrowed**; owner type + runtime remain |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Formats failure / tooltip strings | **Falsified** — pure map arm wrapper |
| 2 | Duration always from skill template fixed field | **Falsified** — stack `nDurationMs` from caller |
| 3 | No start stamp / duration-only | **Falsified** — `mov eax,[0x00b041cc]` → entry.start |
| 4 | `thiscall` on skill object | **Falsified** — `RET 8` stdcall; ECX is map **owner**, not formal this of skill |
| 5 | Insert **updates** existing category rows | **Falsified** (inherited) — Map_Insert equal-key is find-only |
| 6 | Cast-again ctor calls this function | **Falsified** — only ApplyStatusEffectLocal xref; CastAgain → Map_Insert direct |
| 7 | Many unknown callers | **Falsified** — single static xref `0x0051ac77` |
| 8 | DAT_00b041cc units unknown | **Closed High** — symbol `g_dwClientTickMs`, plate ms + peer usage |
| 9 | Finished PDB types / owner class name | **Overstated** — layout recovered; product type open |
| 10 | Thread-safe shared map | **Unproven** — no locks in unit; client ST assumption |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Early-out `-1` | **High** | Arm invalid category |
| Pack now + duration param | **High** | Wrong CD length / start |
| `g_dwClientTickMs` ms clock | **High** | Gauge/remaining skew |
| ABI `RET 8` stdcall | **High** | Stack smash |
| ECX owner → GetMap → Map_Insert | **High** | Write wrong map / crash |
| Equal-key no refresh | **High** | Assume re-cast refreshes category CD |
| Sole static caller | **High** | Missed arm site |
| Owner C++ class name | **Open** | Docs only |
| Server authority parity | **Open** | Client/server desync |
| Runtime capture | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
sub esp,14; push esi
cat = [esp+1C]; if cat==-1 → epilogue
now = [0x00b041cc]; dur = [esp+20]
entry.start=now; entry.dur=dur; entry.key=cat
push &entry; push &outPair
call GetMap          ; ECX still owner
mov ecx, eax
call Map_Insert      ; RET 8
pop esi; add esp,14; ret 8
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Clean updated for stdcall + insert-or-find wording (raw body append-only).

---

## 4. Surviving contract for AutoCore

```
// Client local category CD arm (item-skill status path)
InsertCategoryCooldown(cat, durationMs)  // __stdcall; ECX = cast-owner host
  if cat == -1: return
  entry = { cat, g_dwClientTickMs, durationMs }
  map = GetCategoryCooldownMap(owner)     // lazy *(owner+0x6c)
  Map_InsertOrFind(map, entry)            // NO refresh if key live
  // outPair discarded

// Refresh-while-active: not this API — needs erase (GetRemaining expiry)
// or a different writer. Cast-again arms via Map_Insert directly with same pack.

AutoCore: if simulating client category CD, match insert-or-find + ms now stamp;
server should remain authoritative for true recharge.
```

---

## 5. Open questions

1. Product type name of map owner host (`+0x6c`).
2. Live trace: item path packs `packet+0x10 + period` and category field (caller-owned; optional).
3. Diff vs any server-side category CD map.
4. Bit-exact vs retail EXE image.

**Verdict:** **accept-with-gaps** — CF + ABI + pack + clock + sole caller + no-update-on-equal **sealed**; owner type name + runtime/diff/server open.
