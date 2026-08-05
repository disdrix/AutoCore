# Review A (reconstruction fidelity): `aa_00560f30` WorldObj_ReattachLinksGuarded_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560f30` |
| **VA** | `0x00560f30`–`0x00560f60` |
| **Body** | **48 bytes** |
| **Canonical name** | `WorldObj_ReattachLinksGuarded_Inferred` |
| **Prior scaffold** | `FUN_00560f30` |
| **Review date** | `2026-07-29` (W27-O dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00560f30_WorldObj_ReattachLinksGuarded_Inferred.md` |
| **System** | world-object / phys rebind |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Thin **manager** helper — guarded reattach of a world object:

| Step | Action |
|---|---|
| 1 | Save `*(manager+0x12c)`; set `*(manager+0x12c) = 1` |
| 2 | `FUN_0055e760(obj)` — attach/register onto manager |
| 3 | `FUN_0055fa40(obj)` — `WorldObj_BindLinks_Inferred` |
| 4 | Restore prior flag |

**Not** full enroll (`00560ec0` counters/refcount/notify).  
**Not** `WorldObj_RebindActivate` (`00560e90` uses unbind `0055fbf0` then bind + host flag).

Used by `FUN_005d4440` (SwitchHBAI family) when **new** mode code == **7**.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00560f30` ≡ raw 2026-07-23 |
| Bytes | `read_memory` 64 B — `movsx` save `[esi+0x12c]`; `mov byte [esi+0x12c],1`; dual calls; restore; **`C2 04 00`** |
| Bounds | body `00560f30`–`00560f60` (48 B; pad `CC`) |
| Call site | `get_assembly_context` @ `0x005d46e0`: `PUSH ESI; MOV ECX,EDI; CALL` |
| Callees | `0055e760`, `0055fa40` |
| Caller | `FUN_005d4440` only (1 xref) |
| Siblings | enroll `00560ec0`, rebind `00560e90`, rehome `00560f70` |
| Raw / clean | `aa_00560f30_*`, `WorldObj_ReattachLinksGuarded_Inferred.cpp` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, dual of `0055e760`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX = manager (`mov esi,ecx`) | **Confirmed** | bytes + call site `MOV ECX,EDI` |
| Stack #1 = object | **Confirmed** | `mov edi,[esp+0x10]` after 3 pushes; call site `PUSH ESI` |
| `ret 4` | **Confirmed** | `C2 04 00` |
| Flag save/set1/restore at `+0x12c` (300) | **Confirmed** | bytes + body |
| Order: `0055e760` then `0055fa40` | **Confirmed** | call order |
| Void / no EAX product status | **Confirmed** | no post-call use in body |
| Product manager / mode-7 English | **Open** | structural `_Inferred` |
| Decompiler ≡ live ≡ raw | **Confirmed** | 2026-07-29 |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Save flag; set 1 | Yes |
| call attach (`0055e760`) | Yes |
| call bind (`0055fa40`) | Yes |
| restore flag | Yes |
| ret 4 | Yes |

### Recovered CF

```c
// void __thiscall WorldObj_ReattachLinksGuarded(Manager *m, WorldObj *obj)  // RET 4
uint8_t prev = *(uint8_t *)(m + 0x12c);
*(uint8_t *)(m + 0x12c) = 1;
FUN_0055e760(obj);
FUN_0055fa40(obj);
*(uint8_t *)(m + 0x12c) = prev;
```

### Entry byte seal (48 B)

```
53 56 57                  push ebx/esi/edi
8B 7C 24 10               mov edi, [esp+10h]   ; obj
8B F1                     mov esi, ecx         ; manager
0F BE 9E 2C 01 00 00      movsx ebx, [esi+12Ch]
57                        push edi
C6 86 2C 01 00 00 01      mov byte [esi+12Ch], 1
E8 …                      call FUN_0055e760
57 8B CE E8 …             push edi; mov ecx,esi; call FUN_0055fa40
5F 88 9E 2C 01 00 00      pop edi; mov [esi+12Ch], bl
5E 5B C2 04 00            pop esi/ebx; ret 4
```

---

## 5. Gaps / open

1. Product English for manager class and mode code **7**.
2. Full contract of `FUN_0055e760` (not OWN).
3. Runtime / bit-exact / differential.

**Verdict:** **accept**
