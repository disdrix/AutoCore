# Review B (skeptical / adversarial): `aa_0067ba30` netSocket_GetPeerAddress

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067ba30` |
| **VA** | `0x0067ba30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0067ba30_netSocket_GetPeerAddress.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / outcome |
|---|---|---|
| 1 | This is auth crypto / EncryptAndPrepareAuthRequest body | **Falsified** — body is `getpeername` + Address copy; parent-seed alias is incomplete |
| 2 | Queries **local** bind address | **Falsified** — import is `getpeername`; twin `0067b9a0` is the `getsockname` form |
| 3 | ECX is the out Address being constructed | **Falsified** — entry uses `*ecx` as SOCKET; stack arg is copy destination and return |
| 4 | `__cdecl` / no stack cleanup | **Falsified** — trailer `ret 4` |
| 5 | Checks getpeername return and fails closed | **Falsified** — no branch on API result; always copies temp → out |
| 6 | Address is larger than 16 bytes here | **Falsified for this unit** — `namelen=0x10` and 4-dword copy only |
| 7 | `FUN_0067b110` does non-trivial teardown | **Falsified** — OWN sibling sealed as single `ret` |
| 8 | Product name is sealed | **Survives as open** — role High; PDB spelling not in body |
| 9 | Scaffold Named_CalleeOf_Encrypt… is authoritative naming | **Overstated** — keep as alias only; role is netSocket peer address |
| 10 | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Peer vs local (getpeername) | High | Wrong address source in logs/wire debug |
| ABI thiscall + ret 4 + return out | High | Wrong hooks / wrong out fill |
| 16-byte Address size | High | Buffer overrun / short copy in port |
| Unchecked API result | High CF | Port may over-check; retail does not branch here |
| nazgul netSocket family | High | Mis-file under TNL Socket ctor (different VA cluster) |
| Product method name | Medium/open | Docs-only risk |
| Auth slot which holds netSocket* | Open | Wrong ECX at call site reconstruction |
| Clean is CF-preserving scaffold | High | Low risk as map; high if bit-exact claim |

---

## 3. Surviving contract for AutoCore

```text
// Native VA 0x0067ba30 — nazgul netSocket get peer Address
//
// Address* netSocket_GetPeerAddress(netSocket* self /* ECX */, Address* out /* stack */)
//   // self+0 = SOCKET handle
//   // out   = 16-byte Address / sockaddr overlay
//
// Stages:
//   temp = Address_DefaultCtor();          // FUN_0067b070
//   getpeername(*self, &temp, namelen=16);
//   *out = temp;                           // FUN_0067b0e0 (4 dwords)
//   Address_TrivialDtor(temp);             // FUN_0067b110
//   return out;
//
// Twin local-name: FUN_0067b9a0 (getsockname) — same ABI/shape.
// No error return; getpeername failure still copies (possibly zeroed) temp.
```

**Port rules (AutoCore):**

1. Use for **peer** endpoint of a connected TCP/auth socket — not bind/local name.
2. Out buffer must be **≥ 16 bytes**; do not invent larger layout from this unit alone.
3. Do not invent error handling the retail body lacks unless product requires better diagnostics.
4. Do not confuse with TNL `Socket::Socket` ctor (`0x00785510`) or DES auth encrypt (`0x00728e50`).

**Do not confuse with:**

- `FUN_0067b9a0` (local/`getsockname`).
- `Client_EncryptAndPrepareAuthRequest` (credential DES pack — different VA).
- TNL Address helpers under `0x00784xxx` (related domain, different cluster).

---

## 4. Decompiler alias hazards (attack surface)

| Hazard | Mitigation |
|---|---|
| Call sites show only `FUN_0067ba30(local_buf)` | Recover ECX = socket object from preceding code; stack = out |
| `param_2` typed `undefined4` | Treat as `Address*`; returned |
| `FUN_0067b0e0(&local_1c)` one visible arg | thiscall dest in ECX = out |
| Named_CalleeOf_Encrypt… filename | Alias only; role from body + twin |

---

## 5. Open questions

1. Product/PDB spelling of method.
2. Auth host object: is netSocket at `+0x30` and raw `SOCKET*` at `+0x34` (or inverse)?
3. Whether any caller inspects getpeername failure outside this unit.
4. Address field-level English (sin_family/port/addr) — sibling duals.

**Verdict:** **accept-with-gaps** — adversarial pass does **not** overturn peer-query ABI/CF/size seal; gaps are product name, caller slot map, and runtime. Safe static map for OWN VA.
