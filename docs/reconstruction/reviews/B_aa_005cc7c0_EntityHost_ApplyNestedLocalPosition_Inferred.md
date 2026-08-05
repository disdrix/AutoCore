# Review B (skeptical / adversarial): `aa_005cc7c0` EntityHost_ApplyNestedLocalPosition_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cc7c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005cc7c0_EntityHost_ApplyNestedLocalPosition_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Decompiler signature is complete (`this` + one stack arg) | Epilogue is **`ret 8`** — two stack dwords | **Decomp incomplete** — seal width from bytes |
| 2 | Free-standing calls `FUN_0053d970(0)` / `FUN_004c3a40(vec)` | Both take **ECX=nested** (`mov ecx,[esi+0x64]`) | **Thiscall on nested**, not free globals |
| 3 | Dirty at `+0x304` is a dword flag | Opcode **`C6`** = byte store of imm8 `1` | **Byte**, not dword |
| 4 | This unit is only reached from DriveControlTick | Xrefs are **DATA** only (5 vtables); no CALL | **Virtual multi-type** path — not DCT-only |
| 5 | Prep call is a no-op with arg 0 | Callee `0053d970` **uses** stack arg (`cmp [esp+4],0` → rewrite 1 vs 6) before optional `005d4440` | **Not a no-op** when body path taken; arg0 → code **1** |
| 6 | Name must be SetLocalPosition | Host wrapper: prep + dirty + **delegate** to `004c3a40` | **Host apply** name preferred over duplicating sibling |
| 7 | Arg2 must be a second float* | Never loaded; could be unused interface padding | **Unread** — do not invent type |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `ret 8` / two stack dwords | **High** | Wrong port ABI |
| Nested `+0x64` + dirty `+0x304` byte | **High** | Wrong object / wrong width store |
| Call order prep → dirty → set-pos | **High** | Race with consumers of dirty |
| Vtable-only dispatch | **High** | Missed CALL would change caller inventory |
| Prep always meaningful | **Medium** | Only when nested body path triggers `005d4440` |
| Product name | **Tentative** | Doc only |
| Arg2 type | **Open** | Wrong interface stub |

---

## 3. Cross-check against raw / bytes

```
raw decompile ≡ live decompile CF (3 steps)
bytes seal:
  push esi / mov esi,ecx
  mov ecx,[esi+0x64]; push 0; call 0053d970
  mov eax,[esi+0x64]; mov ecx,[esp+8]; mov byte [eax+0x304],1
  push ecx; mov ecx,[esi+0x64]; call 004c3a40
  pop esi; ret 8
callee 0053d970 ends ret 4 (stack formal cleaned)
DATA xrefs @ 009da9d0 / 009daf58 / 009db0d8 / 009db138 / 009db198 all LE 0x005cc7c0
```

Decompiler free-call form is **documentation-shaped** only; clean Ghidra twin keeps decomp shape; named twin restores thiscall ECX.

---

## 4. Surviving contract for AutoCore

```
// Host virtual — not a gameplay rule to reimplement server-side as-is
void EntityHost_ApplyNestedLocalPosition(host, float localPos[4], /*arg2 unread*/):
  object = host->nested_at_0x64
  PhysOrBodyPrep(object, mode=0)     // client FUN_0053d970
  object->dirty_0x304 = (uint8)1
  CVOGObject_SetLocalPosition4_Gated(object, localPos)

// Port note: sector should keep using managed pose writers; this seals
// retail client host→nested apply + dirty coupling only.
```

Do **not** collapse this into bare `SetLocalPosition` — prep + dirty are part of the sealed order.

---

## 5. Open questions

1. Host class English / which five vtables (entity kinds).
2. Arg2: real unused MSVC artifact vs second channel (quat/flags) never wired in this override.
3. Whether any indirect call sites bypass vtable listing.
4. Live: null nested crash vs always-valid invariant.
5. Interaction of dirty `+0x304` with DriveControlTick (sets same flag after its own set-pos).

**Verdict:** **accept-with-gaps** — adversarial kills single-arg / free-call / dword-dirty misreads; host apply contract stands; name and arg2 remain open.
