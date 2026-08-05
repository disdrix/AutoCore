# Review A (reconstruction fidelity): `aa_005ffc20` CVOGHBToken_OnEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffc20` |
| **VA** | `0x005ffc20` |
| **Canonical name** | `CVOGHBToken_OnEnd` (Ghidra `FUN_005ffc20`; **RTTI Confirmed**) |
| **Review date** | `2026-07-29` (OWN-ONLY dual W17-K) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005ffc20_CVOGHBToken_OnEnd.md` |
| **System** | heartbeat / CVOGHBToken |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Virtual **OnEnd** for `CVOGHBToken` (`vtbl+0x14`):

1. If `this+0x18` (related*) non-null → `related->vtbl[+0x1d4]()` → host.
2. If host non-null **and** `*(int*)(this+0x10) < 1`:
   - Resolve character: MI-adjust host, `vtbl[+0x210](0)`.
   - `Character_SetFlagByte_plus529_WithNetDirty(character, 1)` (`FUN_005208e0`).
3. Tail to empty `FUN_005081f0`.

No other side effects. Virtual-only dispatch (DATA xref from vtable).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `decompile_function` @ `0x005ffc20` ≡ raw |
| Machine | `read_memory` @ `0x005ffc20` length 80 |
| RTTI | type_info `0x00af4660` → `.?AVCVOGHBToken@@` |
| Vtable | `0x009dde2c` dtor `005d6c40`; `+0x14` @ `0x009dde40` = this unit |
| Flag setter dual | `A_aa_005208e0_Character_SetFlagByte_plus529_WithNetDirty_Inferred.md` |
| OnEnd pattern peer | `CVOGHBOKToCastAgain_OnEnd` `0x0051e3b0` (tail empty) |
| Raw / clean / function | `raw/aa_005ffc20_*`, `reconstructed-exact/FUN_005ffc20.cpp`, `functions/aa_005ffc20_*` |

---

## 3. Authoritative body

```c
void __thiscall CVOGHBToken_OnEnd(CVOGHBToken *this)
{
  int *related = *(int **)((char *)this + 0x18);
  if (related) {
    int host = (**(code **)(*related + 0x1d4))();
    if (host && *(int *)((char *)this + 0x10) < 1) {
      void *character =
        (**(code **)(*(int *)(*(int *)(*(int *)(host + 4) + 4) + 4 + host) + 0x210))(0);
      Character_SetFlagByte_plus529_WithNetDirty(character, /*value*/ 1);
    }
  }
  FUN_005081f0(); /* empty ret */
}
```

---

## 4. Machine seal

| Claim | Evidence | Conf |
|---|---|---|
| Class RTTI Token | `.?AVCVOGHBToken@@` @ `0x00af4660` | **High** |
| OnEnd slot `+0x14` | vtbl `0x009dde40` → `0x005ffc20` | **High** |
| Gates `+0x18` / `+0x10<1` | cmp/jcc in body | **High** |
| Set flag 1 via `005208e0` | call target + `push 1` framing | **High** |
| Empty tail | `jmp 0x005081f0` | **High** |
| CF clean ≡ raw ≡ machine | three-rep | **High** |

---

## 5. Confidence

| Claim | Conf |
|---|---|
| Name `CVOGHBToken_OnEnd` | **High** (RTTI + slot) |
| Behavioral CF | **High** |
| `+0x10` product meaning | **Open** |
| `+0x529` product meaning | **Open** (shared residual w/ `aa_005208e0`) |
| Related `+0x1d4` product identity | **Probable** (host resolve; ghost unpack cousin) |

---

## 6. Gaps / open

1. Map character `+0x529` / mask `0x100` to packUpdate wire field.
2. Name `this+0x10` (token remaining / phase).
3. Runtime observation of Token OnEnd under live HB list remove.

**Verdict:** **accept-with-gaps**
