# Review A (reconstruction fidelity): `aa_007fca10` FUN_007fca10

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fca10` |
| **VA** | `0x007fca10` |
| **Canonical name** | `FUN_007fca10` (leave-FUN; no string/RTTI) |
| **Review date** | `2026-07-29` (wave3 dual — UF-010 invoker host) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007fca10_FUN_007fca10.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** (Flush-invoke CF static sealed; rename deferred; runtime open) |

---

## 1. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Ghidra decompile (live 2026-07-29) | `FUN_007fca10` @ `0x007fca10` ≡ frozen raw |
| Raw | `docs/reconstruction/raw/aa_007fca10_FUN_007fca10.md` |
| Annotated | `docs/reconstruction/raw/aa_007fca10_FUN_007fca10.annotated.md` |
| Clean plate | `docs/reconstruction/reconstructed-exact/FUN_007fca10.cpp` |
| Function record | `docs/reconstruction/functions/aa_007fca10_FUN_007fca10.md` |
| Downstream Flush | Ghidra + dual `aa_008ab8f0` @ `0x008ab8f0` |
| Event dispatch | Ghidra `FUN_008aec40` @ `0x008aec40` (CALL site `0x008aef96`) |
| Alt dispatch | Ghidra `FUN_008af020` @ `0x008af020` |
| Vtable base | `0x00a4a51c` |
| Flush DATA slot | `0x00a4a95c` → `read_memory` dword **`0x008ab8f0`** |
| Xrefs | `get_function_xrefs(0x007fca10)` — high fan-in generic close |
| Chain | `reviews/CHAIN_2026-07-29_c2s_206e_seal.md` |

---

## 2. Evidence used

### 2.1 Body (authoritative decompile ≡ raw)

```c
// 0x007fca10 — EAX dialog, EBX client
if ((*(int *)(unaff_EBX + 0xf40) != 0) && (in_EAX != (int *)0x0)) {
  cVar2 = (**(code **)(*in_EAX + 0x3d8))();   // visible?
  if (cVar2 != '\0') {
    (**(code **)(*in_EAX + 0x440))();         // ★ class close / Flush
    // parent +0xb0, table scan +0x1030, optional +0xf38+0x3c4, optional +0x10b0 path
  }
}
```

Clean plate preserves this CF order (no modernization).

### 2.2 When Flush is called (sealed CF)

| # | Gate | Required for `vtbl+0x440` |
|---|---|---|
| 1 | `*(client+0xf40) != 0` | Yes |
| 2 | `dialog (EAX) != null` | Yes |
| 3 | `dialog.vtbl+0x3d8() != 0` | Yes |
| 4 | Then **unconditional** `dialog.vtbl+0x440()` | **Yes — this is the Flush invoke** |

Post-Flush bookkeeping (detach, exclusive scan, restore) does **not** re-gate the Flush call; it runs after.

### 2.3 Mission class: `+0x440` → FlushPreparedResponse

| Item | Value | Confidence |
|---|---|---|
| Host | `client+0x1058` (table index 10) | High |
| Vtable | `0x00a4a51c` | High |
| Offset | `0x440` | High |
| Slot VA | `0x00a4a95c` | High |
| Target | `0x008ab8f0` | **High** (`read_memory` 2026-07-29) |

### 2.4 Mission UI lifecycle → this host

```
Response / close UI event on NPC dialog
  FUN_008aec40:
    • btn 0x9c46..0x9c4d, msg==8 → HandleButton; if non-zero → FUN_007fca10
    • case 40000 (0x9c40), msg==8 → FUN_007fca10   [no HandleButton fill]
  FUN_008af020:
    • HandleButton(0); if non-zero → FUN_007fca10

FUN_007fca10:
  if visible (+0x3d8): call +0x440  → Flush for mission class
```

HideMissionDialogIfOpen is **not** on this path.

### 2.5 UF-011 boundary

This unit does not reference `+0x650`. Cancel still reaches `+0x440` if visible. Clear residual remains on `aa_008ab8f0` / UF-011.

---

## 3. Confirmed claims with confidence

| Claim | Confidence | Notes |
|---|---|---|
| Leave-FUN name correct | **High** | No string/RTTI |
| Clean ≡ decompiler CF | **High** | Order preserved |
| Visible gate is `+0x3d8` before `+0x440` | **High** | Nested if |
| Mission `+0x440` is Flush @ `0x008ab8f0` | **High** | memory + dual |
| Mission dispatch calls this | **High (static)** | decompile 008aec40 / 008af020 |
| Generic multi-dialog host | **High** | xref fan-in |
| EAX/EBX live inputs | **High** (decomp); ABI label Tentative | |
| Parent/`+0x1030` restore semantics | Probable / Tentative | not required for UF-010 seal |

---

## 4. Control flow: clean ≡ decompiler

| Stage | Match |
|---|---|
| Dual gate `+0xf40` + EAX | **Yes** |
| `+0x3d8` then `+0x440` | **Yes** |
| Parent `+0xb0` | **Yes** |
| Table scan skip `0x16`, length `0x3a` | **Yes** |
| Exclusive `obj[0x140]==1` early tail | **Yes** |
| Optional `+0xf38` / `+0x3c4` | **Yes** |
| Optional `+0x10b0` / `+0x664` / `+0x47c` | **Yes** |

---

## 5. Remaining uncertainty

1. Product names for `+0x3d8`, `+0xf40`, `+0xf38`, `+0x10b0`.
2. Table index skip `0x16` and `obj[0x140]` flag meaning.
3. Runtime trace accept → this → Flush (static sealed only).
4. UF-011 cancel clear (owned by Flush unit, not this VA).
5. Whether non-mission callers rely on different `+0x440` methods (expected — generic host).

---

## 6. Verdict

**accept-with-gaps.**

**Sealed for UF-010 invoker CF:** visible (`+0x3d8`) → **`vtbl+0x440`** on the object in EAX, with mission dialog binding proven to Flush @ `0x008ab8f0`. Mission event dispatch (`FUN_008aec40` / `FUN_008af020`) statically calls this host. Gaps: runtime, parent-slot product names, UF-011 clear (out of scope).
