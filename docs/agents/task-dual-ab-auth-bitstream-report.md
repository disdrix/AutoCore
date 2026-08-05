# Dual A/B review batch — Auth* / AuthClient_* / BitStream_* (remaining)

**Date:** 2026-07-23  
**Scope:** Clean units under `docs/reconstruction/reconstructed-exact` matching `Auth*`, `AuthClient_*`, `BitStream_*` that lacked **both** standard `A_aa_*` and `B_aa_*` under `docs/reconstruction/reviews/`.  
**Excluded:** Launcher (never).  
**Cap:** 40 pairs.  
**Count written:** **8 pairs** (16 files).

## Selection

Pre-batch filter scan:

| Family | Clean units | Already dual A+B | Missing both |
|---|---:|---:|---:|
| `AuthClient_*` | 18 | 18 | **0** |
| `BitStream_*` | 7 | 7 | **0** |
| `Auth*` (other) | 47 (incl. address twins / string renames) | 34 | **13 file names / 8 unique VAs** |

Address-suffixed twins (`Auth_*_00xxxxxx.cpp`) share the same VA as the unsuffixed clean when both exist; duals are written **once per VA**.

This batch: **all 8** unique missing VAs (under cap).

Post-batch: **0** `Auth*` / `AuthClient_*` / `BitStream_*` clean units missing both A and B (address-based).

## Pairs written

| # | Stable ID | Name | A verdict | B notes |
|---|---|---|---|---|
| 1 | `aa_00727b70` | Auth_authMessageTrace_00727b70 | accept-with-gaps | **Receiving** tracer; log line `0x12`; not codec |
| 2 | `aa_00727c00` | Auth_authMessageTrace | accept-with-gaps | **Sending** tracer; log line `0xd`; twin of #1 |
| 3 | `aa_007ffcf0` | Auth_Client_FormatUnknownAccountChatLine | accept-with-gaps | chat-log enable/disable banners; `DAT_00d1775c` |
| 4 | `aa_008c92b0` | Auth_Client_RequireAccountName | accept-with-gaps | empty account toast; return 0/1; `+0x590` |
| 5 | `aa_008cb9c0` | Auth_i_d_fesh_2d_wnd_frame_btn_login_xml | accept-with-gaps | **fesh** shard/select chrome; not password form |
| 6 | `aa_008c9830` | Auth_i_d_fet_2d_wnd_frame_btn_login_xml | accept-with-gaps | **fet** entry UI + password; GetKeyboardState/SendInput |
| 7 | `aa_009332b0` | Auth_No_authentication_key | accept-with-gaps | state `+0xc0=2/+0xc4=3`; `FUN_00807490(..., 0x6900)` open |
| 8 | `aa_008223e0` | Auth_Setup_of_CNDAuthClient_failed | accept-with-gaps | **init** with fail branch; not fail-only dialog |

Paths: `docs/reconstruction/reviews/A_aa_<addr>_<Name>.md` and matching `B_aa_*`.

Skipped (already dual via prior AuthClient_* / Client_* / BitStream_* pairs): all `AuthClient_*`, all `BitStream_*`, `AuthRequest_Serialize`, `Auth_AuthServer_*` / string-rename twins already covered by address match (`OnLoginOk`, `OnAuthDisconnected`, etc.).

## High-signal findings (for AutoCore)

1. **authMessageTrace is dual-direction logging only.** `0x00727b70` = `Receiving: %s <- %s(%s)` (line `0x12`); `0x00727c00` = `Sending: %s -> %s(%s)` (line `0xd`). No wire mutation — safe to ignore for server auth authority.
2. **fesh vs fet login UI packs differ.** `i_d_fesh_2d_*` is shard/character select (sort name/capacity, listboxes, scrollbar). `i_d_fet_2d_*` is account entry (password edit, login/options/create/remember/cinematic/quit). Do not conflate.
3. **RequireAccountName** is a pure client gate: widget at form `+0x590`, text via vtbl `+0x1dc`; toast *"You need to specify your Account Name!"*; returns **1** ok / **0** block — no `SendLoginInsecure` inside.
4. **No authentication key** sets two state dwords (`+0xc0=2`, `+0xc4=3`), optional toast when `+0x113` and `+0xa6` clear, then `FUN_00807490(obj+0x730, 0x6900)` — **0x6900 is not sealed as an opcode** without that callee.
5. **Setup_of_CNDAuthClient_failed** is misnamed by string: it **always constructs/inits** the object; only when `FUN_007299e0() < 0` does it `OutputDebugStringA` + `VOG_DEBUG_STOP`. Prefer thinking of it as CNDAuthClient init.
6. **FormatUnknownAccountChatLine** is admin chat-log UX (`Unknown Account` / `Player` / enabled|disabled banners), not AuthServer account validation.
7. **AuthClient_* and BitStream_* families were already dual-complete** before this batch — no recreation.

## Not done

**None** for `Auth*` / `AuthClient_*` / `BitStream_*` dual A/B backlog (unique VAs).

Optional cleanup (out of scope): address-suffixed clean twins could be marked alias-only; string-rename `Auth_*` units that duplicate `Client_*` / `AuthClient_*` VAs already share duals via address match.

Runtime / differential / bit-exact still **open** on all eight.

## Artifacts

- Reviews: `docs/reconstruction/reviews/` (16 new files)
- Writer: `tmp/write_dual_reviews_auth_bitstream_remaining.py`
- Report: `docs/agents/task-dual-ab-auth-bitstream-report.md`
- No Launcher touched; no servers started.
