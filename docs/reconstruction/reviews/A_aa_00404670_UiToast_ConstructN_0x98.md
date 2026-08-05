# Review A (reconstruction fidelity): `aa_00404670` UiToast_ConstructN_0x98

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404670` |
| **VA** | `0x00404670` |
| **Canonical name** | `UiToast_ConstructN_0x98` (structural; product/PDB open) |
| **Ghidra name** | `FUN_00404670` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-S) |
| **Counterpart** | `reviews/B_aa_00404670_UiToast_ConstructN_0x98.md` |
| **System** | `missions-progression` / shared UI toast vector helpers |
| **Verdict** | **accept** on CF / stride / callee / cdecl ABI; product symbol **open** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Count-based POD construct** for UI toast elements of stride **`0x98`**:

```
for (; count != 0; --count) {
  FUN_00404710(dst, src);   // UiToast_PodCopyElement_0x98 (0x26 dwords)
  dst += 0x98;
}
```

- **Not** vector growth / insert (`00403980` / `0040c720`).
- **Not** the leaf pod copy itself (`00404710`).
- **Not** mission grant / toast text formatting.
- Twin of floater `CombatFloater_ConstructN_0x38` (`0x00404600`) with toast width.

Callers:

| Caller | VA | Role |
|---|---|---|
| `Client_UiToastQueue_Push` | `0x0040c5c0` | Fast path: construct **1** element at current `end` |
| `FUN_00404130` | `0x00404130` | Fill-n: ConstructN then `return dst + count*0x98` |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00404670_FUN_00404670.md` |
| Raw | `docs/reconstruction/raw/aa_00404670_FUN_00404670.md` |
| Annotated | `docs/reconstruction/raw/aa_00404670_FUN_00404670.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00404670.cpp` |
| Live decompile | Ghidra `decompile_function` `0x00404670` (2026-07-29) — **≡ raw** |
| Live body bytes | Ghidra `read_memory` entry / loop / epilogue |
| Callers | `get_function_callers`: `00404130`, `0040c5c0` |
| Callee dual | `A_aa_00404710_UiToast_PodCopyElement_0x98.md` |
| Parent dual | `A_aa_0040c5c0_Client_UiToastQueue_Push.md` |

**Not performed:** Launcher, runtime golden, bit-exact image diff, parent ledger edits.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Loop while `count != 0`; `--count` each iter | **Confirmed** | decompile + `sub edi,1` / store / jmp |
| Stride advance **`+0x98`** | **Confirmed** | `81 c6 98 00 00 00` |
| Body callee only `FUN_00404710(dst, src)` | **Confirmed** | relative call target `0x00404710` |
| SEH frame (`LAB_009bc750`, ExceptionList) | **Confirmed** | prolog bytes + decompile locals |
| ABI free / **cdecl** (`ret` = `c3`) | **Confirmed** | epilogue `8b e5 5d c3` |
| Used formals = `(dst, count, src)` | **Confirmed** | body; parent dual documents phantom extra pushes |
| `[ebp+0x14]` → ECX before pod copy unused by leaf | **Confirmed** | `mov ebx,[ebp+14]; mov ecx,ebx` + callee is stdcall no-ECX |
| Role = toast ConstructN (not grow / not mission) | **High** | sealed toast chain duals |
| Product / PDB name | **Open** | structural only |
| Clean ≡ raw ≡ live CF | **Confirmed** | identity |
| Bit-for-bit / runtime harness | **Open** | deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| SEH install | **Yes** |
| Zero count → no pod-copy calls | **Yes** |
| Each iter: `00404710(dst, src)` then `dst += 0x98` | **Yes** |
| SEH teardown + cdecl ret | **Yes** |
| No heap / no end-pointer bump (caller owns end) | **Yes** |

### Recovered CF

```c
// cdecl
void UiToast_ConstructN_0x98(void *dst, int count, const void *src)
{
  // SEH frame (LAB_009bc750)
  for (; count != 0; --count) {
    UiToast_PodCopyElement_0x98(dst, src); // FUN_00404710
    dst = (char *)dst + 0x98;
  }
}
```

### Parent fast-path wiring (`0x0040c5c0`)

```c
slot = this->end;
FUN_00404670(slot, 1, pElem);   // + phantom args in decompile
this->end = slot + 0x98;
```

---

## 5. Assembly contract (from `read_memory`, no `disassemble_bytes`)

```
00404670  55 8b ec 6a ff 68 50 c7 9b 00   ; SEH prolog, handler 0x009bc750
          64 a1 00 00 00 00 50 64 89 25 …
          51 53 56 57 89 65 f0
          c7 45 fc 00 00 00 00             ; try-level 0
          8b 5d 14  8b 7d 0c  8b 75 08     ; ebx=arg4*, edi=count, esi=dst
loop:
          85 ff  76 1d                     ; if count==0 → done
          8b 45 10  50  56                 ; push src, push dst
          8b cb  e8 … → 00404710           ; ECX=arg4 (unused by leaf)
          83 ef 01  89 7d 0c               ; count--
          81 c6 98 00 00 00  89 75 08      ; dst += 0x98
          eb df                            ; jmp loop
done:
          c7 45 fc ff ff ff ff
          8b 4d f4  64 89 0d 00 00 00 00   ; unlink SEH
          5f 5e 5b  8b e5  5d  c3          ; cdecl ret
```

Entry hex (64 B):  
`558bec6aff6850c79b0064a1000000005064892500000000515356578965f0c745fc000000008b5d148b7d0c8b75089085ff761d8b451050568bcbe860000000`

---

## 6. Gaps

1. Retail / PDB symbol.
2. Full `ToastElement` field map (owned by packers / push dual, not this loop).
3. Whether `FUN_00404130` needs its own dual (role sealed here as fill-n wrapper).

**Verdict:** **accept** — sealed ConstructN CF, stride `0x98`, cdecl ABI, and toast-vector role via dualed pod-copy + push parents.
